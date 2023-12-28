#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/*
file redirection to a command

To implement this I need to follow these steps:

*/

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Redirect stdin to the file
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("Error duplicating file descriptor");
        close(fd);
        return 1;
    }

    // Read from stdin and print to stdout
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("%s", buffer);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
