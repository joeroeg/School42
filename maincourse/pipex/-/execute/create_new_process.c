#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) { // Child process
        char *args[] = {"/bin/ls", "-l", NULL};
        execv("/bin/ls", args);
        perror("execv");
        exit(EXIT_FAILURE); // Exit if execv fails
    } else { // Parent process
        wait(NULL); // Wait for the child process to complete
    }

    return EXIT_SUCCESS;
}
