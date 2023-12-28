#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_ARGS 10

/*
main
	parse_command
	fork first command
		redirect input to a file (infile)
		redirect output to a pipe[w]
		execute ft_execvp
	fork second command
		redirect input to a pipe[r]
		redirect output to a file (outfile)
		execute ft_execvp

ft_execvp
	find_path_env
	tokenize_path
	build_full_path
	executable test
		execute_command
	command_not_found

*/

char **parse_command(const char *cmd) {
    char **argv = malloc((MAX_ARGS + 1) * sizeof(char *));
    if (argv == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *temp = strdup(cmd);
    if (temp == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int in_quotes = 0;
    char quote_char = '\0';
    char *arg_start = temp;

    for (char *p = temp; *p != '\0'; p++) {
        // Handle entering and exiting quotes
        if ((*p == '\'' || *p == '"') && (!in_quotes || *p == quote_char)) {
            if (in_quotes) {
                in_quotes = 0;
                *p = '\0';  // Null-terminate the argument
                if (i < MAX_ARGS) {
                    argv[i++] = strdup(arg_start);
                }
            } else {
                in_quotes = 1;
                quote_char = *p;
                arg_start = p + 1;  // Start after the quote
            }
        } else if (*p == ' ' && !in_quotes) {
            *p = '\0';  // Null-terminate the argument
            if (arg_start != p) {  // Avoid empty arguments
                if (i < MAX_ARGS) {
                    argv[i++] = strdup(arg_start);
                }
            }
            arg_start = p + 1;
        }
    }

    if (in_quotes) {
        fprintf(stderr, "Unmatched quote in command\n");
        for (int j = 0; j < i; j++) free(argv[j]);
        free(argv);
        free(temp);
        return NULL;
    }

    // Add the last argument if any and not in quotes
    if (*arg_start != '\0' && !in_quotes && i < MAX_ARGS) {
        argv[i++] = strdup(arg_start);
    }

    argv[i] = NULL; // NULL-terminate the array
    free(temp);
    return argv;
}

const char* find_path_env(char* const envp[]) {
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            return envp[i] + 5;  // Skip the "PATH=" part
        }
    }
    return NULL;  // Return NULL if PATH is not found
}

char** tokenize_path(const char* path) {
    int count = 1; // Start with 1 for the first token
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == ':') {
            count++;
        }
    }

    // Allocate memory for array of strings
    char** dirs = malloc((count + 1) * sizeof(char*)); // +1 for NULL terminator
    if (dirs == NULL) {
        perror("malloc");
        return NULL;
    }

    // Duplicate the path to avoid modifying the original string
    char* path_dup = strdup(path);
    if (path_dup == NULL) {
        free(dirs);
        perror("strdup");
        return NULL;
    }

    // Tokenize the path
    char* token = strtok(path_dup, ":");
    int index = 0;
    while (token != NULL) {
        dirs[index] = strdup(token);
        if (dirs[index] == NULL) {
            // Clean up in case of allocation failure
            for (int j = 0; j < index; j++) {
                free(dirs[j]);
            }
            free(dirs);
            free(path_dup);
            perror("strdup");
            return NULL;
        }
        index++;
        token = strtok(NULL, ":");
    }
    dirs[index] = NULL; // NULL-terminate the array

    // Clean up
    free(path_dup);

    return dirs;
}

char* build_full_path(const char* dir, const char* file) {
    if (dir == NULL || file == NULL) {
        return NULL;  // Handle null inputs
    }

    // Calculate the required length
    size_t length = strlen(dir) + 1 + strlen(file) + 1;  // +1 for slash and +1 for null-terminator

    // Allocate memory for the full path
    char* fullPath = malloc(length);
    if (fullPath == NULL) {
        perror("malloc");
        return NULL;
    }

    // Construct the full path
    snprintf(fullPath, length, "%s/%s", dir, file);

    return fullPath;
}

int	execute_command(const char* fullPath, char* const argv[]) {
    pid_t pid = fork();  // Fork a new process

    if (pid == -1) {
        // Fork failed
        perror("fork");
        return -1;
    } else if (pid == 0) {
        // Child process
        execv(fullPath, argv);  // Execute the command
        perror("execv");        // execv only returns if there is an error
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);  // Wait for the child process to finish
        if (WIFEXITED(status)) {   // Check if the child exited normally
            return WEXITSTATUS(status);  // Return the exit status of the child
        } else {
            return -1;  // Child did not exit normally
        }
    }
}

void command_not_found(const char* file) {
    fprintf(stderr, "%s: command not found\n", file);
}

int ft_execvp(const char *file, char *const argv[], char *const envp[]) {
	const char *path_const = find_path_env(envp);
    if (path_const == NULL) {
        fprintf(stderr, "PATH not found\n");
        return -1;
    }
    char *path = strdup(path_const);
    if (path == NULL) {
        perror("strdup");
        return -1;
    }
	char** directories = tokenize_path(path_const);
	for (int i = 0; directories[i] != NULL; i++) {
        char* fullPath = build_full_path(directories[i], file);
        if (access(fullPath, X_OK) == 0) {
            int status = execute_command(fullPath, argv);
            free(fullPath);
            free(directories);
            return status;
        }
        free(fullPath);
    }
    free(directories);

    command_not_found(file);
    return -1;
}

int main(int argc, char **argv, char **envp) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_file> \"<cmd1>\" \"<cmd2>\" <output_file>\n", argv[0]);
        return 1;
    }

    char **cmd1_args = parse_command(argv[2]);
    char **cmd2_args = parse_command(argv[3]);

    int pipe_fds[2];
    if (pipe(pipe_fds) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t cmd1, cmd2;

    // Fork for the first command
    cmd1 = fork();
    if (cmd1 == -1) {
        perror("fork");
        return 1;
    }

    if (cmd1 == 0) {
        int infile_fd = open(argv[1], O_RDONLY);
        if (infile_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(infile_fd, STDIN_FILENO);
        close(infile_fd);

        dup2(pipe_fds[1], STDOUT_FILENO);
        close(pipe_fds[0]);
        close(pipe_fds[1]);

        ft_execvp(argv[2], cmd1_args, envp);
        // ft_execvp(argv[2], &argv[2], envp);
        exit(EXIT_FAILURE);
    }

    // Fork for the second command
    cmd2 = fork();
    if (cmd2 == -1) {
        perror("fork");
        return 1;
    }

    if (cmd2 == 0) {
        close(pipe_fds[1]);
        dup2(pipe_fds[0], STDIN_FILENO);
        close(pipe_fds[0]);

        int outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        dup2(outfile_fd, STDOUT_FILENO);
        close(outfile_fd);

        ft_execvp(argv[3], cmd2_args, envp);
        // ft_execvp(argv[3], &argv[3], envp);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; cmd1_args[i] != NULL; i++) free(cmd1_args[i]);
    free(cmd1_args);

    for (int i = 0; cmd2_args[i] != NULL; i++) free(cmd2_args[i]);
    free(cmd2_args);

    // Parent process
    close(pipe_fds[0]);
    close(pipe_fds[1]);

    waitpid(cmd1, NULL, 0);
    waitpid(cmd2, NULL, 0);

    return 0;
}
