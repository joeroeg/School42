#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    // Create a file where the output of the command will be written
    int fd = open("ls_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Fork a new process
    pid_t pid = fork();
    if (pid == -1) {
        // If fork() fails, print an error message
        perror("fork");
        close(fd);
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // Child process

        // Use dup2 to redirect standard output to the file descriptor
        if (dup2(fd, STDOUT_FILENO) == -1) {
            perror("dup2");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Close the original file descriptor as it's no longer needed
        close(fd);

        // Execute the "ls" command which writes the output to the file
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);  // If execvp returns, it must have failed

        perror("execvp");  // execvp() only returns on error
        exit(EXIT_FAILURE);
    } else {
        // Parent process

        // Close the file descriptor as the parent does not need it
        close(fd);

        // Wait for the child process to complete
        waitpid(pid, NULL, 0);
    }

    return EXIT_SUCCESS;
}
