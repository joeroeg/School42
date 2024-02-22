#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL};
    char *env[] = {NULL};

    if (execve("/bin/ls", args, env) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }

    // This line will not be executed if execve is successful.
    printf("This will not be printed if execve is successful.\n");

    return 0;
}
