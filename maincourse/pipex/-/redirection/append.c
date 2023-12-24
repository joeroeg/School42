#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void append_output_to_file(const char* filename) {
    int file_fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file_fd < 0) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int original_stdout = dup(STDOUT_FILENO);
    if (original_stdout == -1) {
        perror("Failed to duplicate stdout");
        close(file_fd);
        exit(EXIT_FAILURE);
    }

    if (dup2(file_fd, STDOUT_FILENO) < 0) {
        perror("Failed to redirect stdout to file");
        close(file_fd);
        exit(EXIT_FAILURE);
    }

    close(file_fd); // Close the original file descriptor

    // Your command logic here. For example, a simple printf
    printf("This text will be appended to the file.\n");

    // Reset stdout
    if (dup2(original_stdout, STDOUT_FILENO) < 0) {
        perror("Failed to reset stdout");
        exit(EXIT_FAILURE);
    }

    close(original_stdout); // Close the duplicate of the original stdout
}

int main() {
    append_output_to_file("output.txt");
    // Standard output is now back to normal
    printf("This will be printed to the standard output again.\n");
    return 0;
}
