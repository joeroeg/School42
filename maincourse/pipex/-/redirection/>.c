#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Step 1: Open the file for writing
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_descriptor < 0) {
        perror("Could not open output.txt");
        return EXIT_FAILURE;
    }

    // Step 2: Redirect stdout to the file
    if (dup2(file_descriptor, STDOUT_FILENO) < 0) {
        perror("Could not redirect stdout to output.txt");
        close(file_descriptor);
        return EXIT_FAILURE;
    }

    // Step 3: The original file descriptor is now redundant, so it can be closed
    close(file_descriptor);

    // Now, any output to stdout will go to "output.txt"
    printf("This will be written to output.txt\n");

    // Flush stdout to ensure all output has been written to the file
    fflush(stdout);

    // Continuing with the program, the output will keep going to "output.txt"
    // ...

    return EXIT_SUCCESS;
}
