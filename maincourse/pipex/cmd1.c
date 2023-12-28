#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"<command> [args]\"\n", argv[0]);
        return 1;
    }

    char *cmd = argv[1];
    char *args[MAX_ARGS];
    char *token;
    int i = 0;

    // Tokenize the input string
    token = strtok(cmd, " ");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // NULL-terminate the arguments array

    // Create a child process
    pid_t pid = fork();

    if (pid == -1) {
        // Error handling
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args);

        // If execvp returns, an error occurred
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for the child process to finish
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
