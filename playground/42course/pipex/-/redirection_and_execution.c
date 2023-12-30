#include <unistd.h>   // for close, dup, dup2, read, write
#include <fcntl.h>    // for open
#include <stdio.h>    // for perror
#include <stdlib.h>   // for exit
#include <sys/wait.h> // for waitpid
#include <sys/stat.h> // for stat
#include <string.h>   // for strtok, strcat, strcpy

#define BUFFER_SIZE 1024

// Function to redirect stdin to the specified file
int redirect_stdin(const char *filename) {
    int file_fd = open(filename, O_RDONLY);
    if (file_fd < 0) {
        perror("Failed to open file");
        return -1;
    }

    int stdin_copy = dup(STDIN_FILENO);
    if (stdin_copy < 0) {
        perror("Failed to duplicate stdin");
        close(file_fd);
        return -1;
    }

    if (dup2(file_fd, STDIN_FILENO) < 0) {
        perror("Failed to redirect stdin to file");
        close(file_fd);
        close(stdin_copy);
        return -1;
    }

    close(file_fd);
    return stdin_copy;  // Return the duplicate file descriptor
}

// Function to check if a file exists and is executable
int is_executable(const char *path) {
    return access(path, X_OK) == 0;
}

// Function to find the full path of an executable
char *find_executable(const char *command) {
    char *path = getenv("PATH");
    char *path_copy = strdup(path); // Duplicate since strtok modifies the string
    if (!path_copy) {
        perror("strdup");
        return NULL;
    }

    char *dir = strtok(path_copy, ":");
    while (dir) {
        char full_path[BUFFER_SIZE];
        snprintf(full_path, BUFFER_SIZE, "%s/%s", dir, command);
        if (is_executable(full_path)) {
            free(path_copy);
            return strdup(full_path); // Caller must free this
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

// Function to execute a command with arguments
void execute_command(char *command, char *const argv[]) {
    char *executable = find_executable(command);
    if (!executable) {
        fprintf(stderr, "Command not found: %s\n", command);
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        free(executable);
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        execv(executable, argv);
        perror("execv");
        free(executable);
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        free(executable);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <command> [command_args...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Redirect stdin to read from the specified file in argv[1]
    int stdin_copy = redirect_stdin(argv[1]);
    if (stdin_copy < 0) {
        exit(EXIT_FAILURE);
    }

    // Create a pipe for inter-communication
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork first process to execute first command
    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Execute first command and redirect output
    if (pid1 == 0) {
        // Child process 1: Execute first command
        close(pipefd[0]); // Close unused read end
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }
        close(pipefd[1]);

    //     int stdin_copy = redirect_stdin(argv[1]);
    //     if (stdin_copy < 0) {
    //         exit(EXIT_FAILURE);
    //     }

    //     execute_command(argv[2], &argv[2]);
    // }

    // pid_t pid2 = fork();
    // if (pid2 == -1) {
    //     perror("fork");
    //     exit(EXIT_FAILURE);
    // }
    // printf("->");
    // if (pid2 == 0) {
    //     // Child process 2: Execute second command
    //     close(pipefd[1]); // Close unused write end
    //     if (dup2(pipefd[0], STDIN_FILENO) == -1) {
    //         perror("dup2");
    //         exit(EXIT_FAILURE);
    //     }
    //     close(pipefd[0]);
    //     int out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    //     if (out_fd == -1) {
    //         perror("open");
    //         exit(EXIT_FAILURE);
    //     }
    //     if (dup2(out_fd, STDOUT_FILENO) == -1) {
    //         perror("dup2");
    //         close(out_fd);
    //         exit(EXIT_FAILURE);
    //     }
    //     close(out_fd);
    //     execute_command(argv[3], &argv[3]);
    // }

    // Parent process
    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    // waitpid(pid2, NULL, 0);

    return 0;
}
