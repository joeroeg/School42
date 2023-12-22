#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void redirect_output(const char* filename) {
    int file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (dup2(file_fd, STDOUT_FILENO) < 0) { // Redirect stdout to file
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    close(file_fd); // Close the original file descriptor
}

int main() {
    redirect_output("output.txt");
    // Now, any standard output will go to "output.txt"
    printf("This will be written to output.txt\n");

    // Remember to reset the standard output if necessary
    return 0;
}
