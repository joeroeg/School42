#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fileDescriptor;
    char buffer[100];

    // Open the file for reading
    fileDescriptor = open("input.txt", O_RDONLY);
    if (fileDescriptor < 0) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Redirect stdin to the file
    if (dup2(fileDescriptor, STDIN_FILENO) < 0) {
        perror("Error duplicating file descriptor");
        close(fileDescriptor);
        return EXIT_FAILURE;
    }

    // Close the original file descriptor as it's no longer needed
    close(fileDescriptor);

    // Now read from stdin (which is redirected to the file)
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("Read from file: %s", buffer);
    }

    return EXIT_SUCCESS;
}
