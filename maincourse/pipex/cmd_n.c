#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

void parse_command(char *cmd, char **args) {
    char *token;
    int i = 0;
    token = strtok(cmd, " ");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s \"<command1> [args]\" ... \"<commandN> [args]\"\n", argv[0]);
        return 1;
    }

    int num_commands = argc - 1;
    int (*pipes)[2] = malloc(sizeof(int[2]) * (num_commands - 1));

    for (int i = 0; i < num_commands - 1; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_commands; i++) {
        if (fork() == 0) {
            if (i > 0) {
                // Not the first command, get input from the previous pipe
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }
            if (i < num_commands - 1) {
                // Not the last command, output to the next pipe
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            // Close all pipe ends in the child
            for (int j = 0; j < num_commands - 1; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            char *args[MAX_ARGS];
            parse_command(argv[i + 1], args);
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }

    // Close all pipe ends in the parent
    for (int i = 0; i < num_commands - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for all children
    for (int i = 0; i < num_commands; i++) {
        wait(NULL);
    }

    free(pipes);
    return 0;
}
