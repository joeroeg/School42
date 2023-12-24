#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", NULL}; // Argument list must end with NULL
    execv("/bin/ls", args); // Replaces the current process with /bin/ls
    perror("execv"); // This will only execute if execv fails
    return EXIT_FAILURE;
}

