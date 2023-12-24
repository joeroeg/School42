#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Open a file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Write something to the file
    const char *msg = "This is written directly to the file.\n";
    if (write(fd, msg, strlen(msg)) < 0) {
        perror("write");
        close(fd);
        return EXIT_FAILURE;
    }

    // Duplicate the file descriptor
    int copy_fd = dup(fd);
    if (copy_fd < 0) {
        perror("dup");
        close(fd);
        return EXIT_FAILURE;
    }

    // Use dup2 to duplicate the file descriptor to stdout
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        close(copy_fd);
        return EXIT_FAILURE;
    }

    // Now, anything written to stdout goes to output.txt
    printf("This is written to stdout, but will end up in the file.\n");

    // Cleanup
    close(fd); // Closing original file descriptor
    close(copy_fd); // Closing duplicated file descriptor

    return EXIT_SUCCESS;
}
