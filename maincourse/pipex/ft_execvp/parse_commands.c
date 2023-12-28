#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_ARGS 10

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
    char *token = strtok(temp, " ");
    while (token != NULL && i < MAX_ARGS) {
        argv[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    argv[i] = NULL; // NULL-terminate the array

    free(temp);
    return argv;
}

void print_args(char **args) {
    if (args == NULL) {
        printf("No arguments.\n");
        return;
    }
    for (int i = 0; args[i] != NULL; i++) {
        printf("arg[%d]: %s\n", i, args[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command1> <command2> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        printf("Testing command: %s\n", argv[i]);
        char **args = parse_command(argv[i]);
        print_args(args);

        // Free the dynamically allocated argument arrays
        for (int j = 0; args[j] != NULL; j++) {
            free(args[j]);
        }
        free(args);
        printf("\n");
    }

    return 0;
}
