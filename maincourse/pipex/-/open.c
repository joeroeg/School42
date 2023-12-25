#include <fcntl.h>   // for open
#include <unistd.h>  // for read, write, close
#include <stdio.h>   // for perror
#include <stdlib.h>  // for exit

#define BUFFER_SIZE 1024

int main() {
    int fd = open("infile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            perror("Error writing to stdout");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
