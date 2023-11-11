#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// void run_test(const char* file_name) {
//     int fd = open(file_name, O_RDONLY);
//     char *line;
//     if (fd == -1) {
//         perror("Error opening file");
//         return;
//     }

//     while ((line = get_next_line(fd)) != NULL) {
//         printf("Retrieved line: %s", line);
//         // Here you can add checks against expected lines
//         free(line);
//     }

//     close(fd);
// }

// int main() {
//     run_test("file.txt");
//     // Add more test files as needed
//     return 0;
// }


int main() {
    int fd = open("file.txt", O_RDONLY); // Open the file for reading
    if (fd == -1) // If open() returns -1, something went wrong
	{
        perror("Error opening file");
        return 1;
    }

    // const int BUFFER_SIZE = 100; // Read up to 100 bytes at a time
    char buffer[BUFFER_SIZE]; // Create a buffer to store our data
    ssize_t bytes_read; // Create a variable to store how many bytes we've read

    bytes_read = read(fd, buffer, BUFFER_SIZE - 1); // Read up to BUFFER_SIZE - 1 bytes
    if (bytes_read == -1) // If read() returns -1, something went wrong
	{
        perror("Error reading file");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0'; // Null-terminate the string in buffer (so string functions work)
    printf("Read %zd bytes: %s\n", bytes_read, buffer); // Print the number of bytes, and the data we read

    close(fd);
    return 0;
}
