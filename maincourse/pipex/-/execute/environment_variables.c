#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"/usr/bin/env", NULL};
    char *envp[] = {"HOME=/myhome", "PATH=/bin:/usr/bin", NULL};

    execve("/usr/bin/env", args, envp); // execve allows specifying env variables
    perror("execve");
    return EXIT_FAILURE;
}
