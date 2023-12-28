#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/*
    FD 0 (input)
    FD 1 (output)
    FD 2 (error)

    pipe [0] (read)
    pipe [1] (write)

    QUESTIONS
    1. why do we redirect a second child to a
*/

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
    if (argc != 3) {
        fprintf(stderr, "Usage: %s \"<command1> [args]\" \"<command2> [args]\"\n", argv[0]);
        return 1;
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1, pid2;

    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Child 1
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);

        char *args1[MAX_ARGS];
        parse_command(argv[1], args1);
        execvp(args1[0], args1);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent
        if ((pid2 = fork()) == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) {
            // Child 2
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[1]);
            close(pipefd[0]);

            char *args2[MAX_ARGS];
            parse_command(argv[2], args2);
            execvp(args2[0], args2);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent
            close(pipefd[0]);
            close(pipefd[1]);
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
        }
    }

    return 0;
}
