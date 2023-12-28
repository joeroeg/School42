#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // The command to run is the first argument. The rest are its arguments.
    // execvp expects the first element of the argument array to be the command.
    execvp(argv[1], &argv[1]);

    // If execvp returns, an error occurred
    perror("execvp");
    return EXIT_FAILURE;
}
