#include <fcntl.h>   // for open flags
#include <sys/stat.h> // for permission flags
#include <unistd.h>  // for close
#include <stdio.h>   // for perror

int main() {
    // File path and name
    const char *filePath = "example.txt";

    // Open the file with O_CREAT flag to create it if it doesn't exist
    // O_WRONLY flag is used to open the file for write-only access
    // 0644 sets the file permissions (owner can read/write, others can read)
    int fileDescriptor = open(filePath, O_CREAT | O_WRONLY, 0644);

    // Check if file creation was successful
    if (fileDescriptor == -1) {
        // If open() returns -1, an error occurred
        perror("Error opening file");
        return 1;
    }

    // Close the file
    if (close(fileDescriptor) == -1) {
        // If close() returns -1, an error occurred while closing
        perror("Error closing file");
        return 1;
    }

    printf("File '%s' created successfully\n", filePath);
    return 0;
}
