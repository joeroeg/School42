#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *file = fopen("non_existent_file.txt", "r");
    if (file == NULL) {
        // An error occurred while opening the file.
        // Check the value of errno to determine the exact error.
        perror("Error");
        // Alternatively, you can directly access the errno variable like this:
        // printf("Error: %s\n", strerror(errno));
        // Note that perror() prints a user-friendly error message based on errno.

        // Take appropriate action based on the specific error.
        if (errno == ENOENT) {
            printf("File not found.\n");
        } else if (errno == EACCES) {
            printf("Permission denied.\n");
        } else {
            printf("Unknown error.\n");
        }

        // Clean up and exit the program.
        exit(EXIT_FAILURE);
    }

    // File opened successfully; proceed with file processing.

    fclose(file);
    return 0;
}
