#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // Open a file for writing
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write something to the file
    write(fd, "Writing directly to the file.\n", 30);

    // Duplicate the stdout file descriptor
    int stdout_copy = dup(STDOUT_FILENO);
    if (stdout_copy < 0) {
        perror("dup");
        close(fd);
        return 1;
    }

    // Redirect stdout to the file
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }

    // Now, this should go to the file
    printf("This goes to the file.\n");

    // Flush stdout to make sure all output has been written to the file
    fflush(stdout);

    // Restore the original stdout using dup2
    if (dup2(stdout_copy, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        close(stdout_copy);
        return 1;
    }

    // Now, this should go to the terminal
    printf("This goes to the terminal.\n");

    // Close the file descriptors
    close(fd);
    close(stdout_copy);

    return 0;
}
