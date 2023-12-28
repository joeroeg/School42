#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

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
    if (argc != 4) {
        fprintf(stderr, "Usage: %s \"<command1> [args]\" \"<command2> [args]\" \"<command3> [args]\"\n", argv[0]);
        return 1;
    }

    int pipefd1[2], pipefd2[2];
    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1, pid2, pid3;

    // First Child
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Redirect stdout to pipefd1 write end
        dup2(pipefd1[1], STDOUT_FILENO);
        close(pipefd1[0]);
        close(pipefd1[1]);

        char *args1[MAX_ARGS];
        parse_command(argv[1], args1);
        execvp(args1[0], args1);
        perror("execvp first command");
        exit(EXIT_FAILURE);
    }

    // Parent closes the write end of the first pipe
    close(pipefd1[1]);

    // Second Child
    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Redirect stdin to pipefd1 read end and stdout to pipefd2 write end
        dup2(pipefd1[0], STDIN_FILENO);
        dup2(pipefd2[1], STDOUT_FILENO);
        close(pipefd1[0]);
        close(pipefd2[0]);
        close(pipefd2[1]);

        char *args2[MAX_ARGS];
        parse_command(argv[2], args2);
        execvp(args2[0], args2);
        perror("execvp second command");
        exit(EXIT_FAILURE);
    }

    // Parent closes the read end of the first pipe and the write end of the second pipe
    close(pipefd1[0]);
    close(pipefd2[1]);

    // Third Child
    if ((pid3 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid3 == 0) {
        // Redirect stdin to pipefd2 read end
        dup2(pipefd2[0], STDIN_FILENO);
        close(pipefd2[0]);

        char *args3[MAX_ARGS];
        parse_command(argv[3], args3);
        execvp(args3[0], args3);
        perror("execvp third command");
        exit(EXIT_FAILURE);
    }

    // Parent closes the read end of the second pipe
    close(pipefd2[0]);

    // Wait for all children
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}
