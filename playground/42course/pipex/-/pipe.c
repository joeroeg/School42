#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
    // Child process
    close(fd[1]); // Close write-end

    char buffer[100];
    read(fd[0], buffer, sizeof(buffer));
    printf("Child received: %s\n", buffer);

    close(fd[0]);
    _exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(fd[0]); // Close read-end

        char *msg = "Hello from parent!";
        write(fd[1], msg, strlen(msg) + 1);

        close(fd[1]);
        wait(NULL); // Wait for child to finish
}

}
