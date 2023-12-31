#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Concatenates directory, a slash, and file into the buffer.
 * Ensures the buffer is null-terminated.
 *
 * @param buffer The buffer to write the result into.
 * @param bufferSize The size of the buffer.
 * @param directory The directory path.
 * @param file The file name.
 * @return The number of characters written (excluding null terminator)
 *         or -1 if the buffer is not large enough.
 */
int custom_snprintf(char *buffer, size_t bufferSize, const char *directory, const char *file) {
    size_t dirLength = strlen(directory);
    size_t fileLength = strlen(file);

    // Check if the buffer is large enough
    if (bufferSize < dirLength + fileLength + 2) {
        return -1; // Indicate buffer too small
    }

    // Copy directory to buffer
    strcpy(buffer, directory);

    // Add slash
    buffer[dirLength] = '/';

    // Copy file name
    strcpy(buffer + dirLength + 1, file);

    return dirLength + fileLength + 1; // Return the number of characters written
}

// Usage example
int main() {
    char buffer[256];
    const char *directory = "/usr/bin";
    const char *file = "ls";

    int result = custom_snprintf(buffer, sizeof(buffer), directory, file);
    if (result != -1) {
        printf("Result: %s\n", buffer);
    } else {
        printf("Buffer too small.\n");
    }

    return 0;
}
