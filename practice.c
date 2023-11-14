#include <stdio.h>
#include <stdlib.h>	 // For dynamic memory allocation
#include <fcntl.h>   // For open
#include <unistd.h>  // For read and close
#include <stdlib.h>  // For malloc, free
#include <string.h>  // For memcpy
#include <stdbool.h> // For bool type


typedef struct CircularBuffer
{
    char *buffer;     // Pointer to the buffer array that holds the data
    size_t capacity;  // Total size of the buffer
    size_t head;      // Index of the head (read pointer)
    size_t tail;      // Index of the tail (write pointer)
    size_t count;     // Number of characters currently in the buffer
} CircularBuffer;

// Function to initialize the circular buffer
CircularBuffer* createCircularBuffer(size_t capacity) {
    // Allocate memory for the CircularBuffer struct
    CircularBuffer *cb = (CircularBuffer *)malloc(sizeof(CircularBuffer));
    if (cb == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Allocate memory for the buffer array within the struct
    cb->buffer = (char *)malloc(capacity * sizeof(char));
    if (cb->buffer == NULL) {
        // Handle memory allocation failure
        free(cb); // Free the previously allocated CircularBuffer struct
        return NULL;
    }

    // Initialize the rest of the fields
    cb->capacity = capacity;
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;

    return cb;
}

// Function to free the circular buffer
void freeCircularBuffer(CircularBuffer *cb) {
    if (cb != NULL) {
        free(cb->buffer); // Free the buffer array
        free(cb);         // Free the CircularBuffer struct
    }
}

// char* extractLine(CircularBuffer *cb) {
//     // Calculate the length of the line
//     size_t lineLength = 0;
//     size_t current = cb->head;
//     bool foundNewLine = false;

//     while (cb->count > 0 && !foundNewLine) {
//         if (cb->buffer[current] == '\n') {
//             foundNewLine = true;
//             break;
//         }
//         lineLength++;
//         current = (current + 1) % cb->capacity;
//     }

//     if (!foundNewLine) {
//         return NULL; // Newline not found in the buffer
//     }

//     // Allocate memory for the line
//     char *line = malloc(lineLength + 1); // +1 for null terminator
//     if (line == NULL) {
//         // Handle memory allocation failure
//         return NULL;
//     }

//     // Copy the line from the buffer
//     for (size_t i = 0; i < lineLength; i++) {
//         line[i] = cb->buffer[cb->head];
//         cb->head = (cb->head + 1) % cb->capacity;
//         cb->count--;
//     }
//     line[lineLength] = '\0'; // Null-terminate the string

//     // Skip the newline character in the buffer
//     cb->head = (cb->head + 1) % cb->capacity;
//     cb->count--;

//     return line;
// }

// char* extractLine(CircularBuffer *cb) {
//     size_t lineLength = 0;
//     // Calculate the length of the line
//     size_t current = cb->head;
//     while (cb->buffer[current] != '\n' && cb->count > 0) {
//         lineLength++;
//         current = (current + 1) % cb->capacity;
//         cb->count--;
//     }

//     // Allocate memory for the line
//     char *line = malloc(lineLength + 1); // +1 for null terminator
//     if (line == NULL) {
//         // Handle memory allocation failure
//         return NULL;
//     }

//     // Copy the line from the buffer
//     for (size_t i = 0; i < lineLength; i++) {
//         line[i] = cb->buffer[cb->head];
//         cb->head = (cb->head + 1) % cb->capacity;
//     }
//     line[lineLength] = '\0'; // Null-terminate the string

//     // Skip the newline character in the buffer
//     cb->head = (cb->head + 1) % cb->capacity;
//     cb->count--;

//     return line;
// }

char* extractLine(CircularBuffer *cb) {
    size_t lineLength = 0;
    // Calculate the length of the line
    size_t current = cb->head;
    while (lineLength < cb->count) {
        if (cb->buffer[current] == '\n') {
            break; // Stop when a newline character is found
        }
        lineLength++;
        current = (current + 1) % cb->capacity;
    }

    // If no newline character was found and we have read everything, return NULL
    if (lineLength == cb->count) {
        return NULL;
    }

    // Allocate memory for the line
    char *line = malloc(lineLength + 1); // +1 for null terminator
    if (line == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Copy the line from the buffer
    for (size_t i = 0; i < lineLength; i++) {
        line[i] = cb->buffer[cb->head];
        cb->head = (cb->head + 1) % cb->capacity;
    }
    line[lineLength] = '\0'; // Null-terminate the string

    // Skip the newline character in the buffer
    cb->head = (cb->head + 1) % cb->capacity;
    cb->count--;

    return line;
}

// Function to read a line from a file using a circular buffer
char* readLine(int fd, CircularBuffer *cb) {
    char tempBuffer[1024]; // Temporary buffer for reading chunks
    ssize_t bytesRead;
    size_t lineLength = 0;
    char *line = NULL;

    while (1) {
        // Read a chunk of data into the temporary buffer
        bytesRead = read(fd, tempBuffer, sizeof(tempBuffer));
        if (bytesRead <= 0) {
            // Handle end of file or read error
            break;
        }

        // Store the chunk in the circular buffer
        for (ssize_t i = 0; i < bytesRead; ++i) {
            // Add each character to the circular buffer
            // Implement logic to handle buffer full scenario
            // ...

            // Check for newline character
            if (tempBuffer[i] == '\n') {
                // Extract the line from the circular buffer
                // Implement logic to handle line extraction
                // ...
				// printf("lineLength: %ld\n", lineLength);
				line = extractLine(cb);
				printf("line: %s\n", line);
                return line;
            }
        }
    }

    // Handle case where the last line doesn't end with a newline
    if (lineLength > 0) {
        return line;
    }

    return NULL; // No more lines to read
}

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        // Handle file open error
        return 1;
    }

    CircularBuffer *cb = createCircularBuffer(4096); // Create a circular buffer
    if (cb == NULL) {
        // Handle buffer creation error
        close(fd);
        return 1;
    }

    char *line;
    while ((line = readLine(fd, cb)) != NULL) {
        // Process the line
        printf("%s\n", line);
        free(line); // Free the line after processing
    }

    freeCircularBuffer(cb); // Free the circular buffer
    close(fd); // Close the file
    return 0;
}


// -------------------------------------------------------------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct CircularBuffer
// {
//     char *buffer;     // Pointer to the buffer array that holds the data
//     size_t capacity;  // Total size of the buffer
//     size_t head;      // Index of the head (read pointer)
//     size_t tail;      // Index of the tail (write pointer)
//     size_t count;     // Number of characters currently in the buffer
// } CircularBuffer;

// char* extractLine(CircularBuffer *cb) {
//     size_t lineLength = 0;
//     // Calculate the length of the line
//     size_t current = cb->head;
//     while (lineLength < cb->count) {
//         if (cb->buffer[current] == '\n') {
//             break; // Stop when a newline character is found
//         }
//         lineLength++;
//         current = (current + 1) % cb->capacity;
//     }

//     // If no newline character was found and we have read everything, return NULL
//     if (lineLength == cb->count) {
//         return NULL;
//     }

//     // Allocate memory for the line
//     char *line = malloc(lineLength + 1); // +1 for null terminator
//     if (line == NULL) {
//         // Handle memory allocation failure
//         return NULL;
//     }

//     // Copy the line from the buffer
//     for (size_t i = 0; i < lineLength; i++) {
//         line[i] = cb->buffer[cb->head];
//         cb->head = (cb->head + 1) % cb->capacity;
//     }
//     line[lineLength] = '\0'; // Null-terminate the string

//     // Skip the newline character in the buffer
//     cb->head = (cb->head + 1) % cb->capacity;
//     cb->count--;

//     return line;
// }


// int main() {
//     // Create a CircularBuffer structure with a capacity of 10
//     CircularBuffer cb;
//     cb.capacity = 1024;
//     cb.buffer = malloc(cb.capacity);
//     cb.head = 0;
//     cb.tail = 0;
//     cb.count = 0;

//     // Fill the buffer with some sample data (for demonstration purposes)
//     char sampleData[] = "Hello\nWorld!\nThis is a\nSample\n";
//     for (size_t i = 0; sampleData[i] != '\0'; i++) {
//         // Check for buffer full scenario (you may need additional handling)
//         if (cb.count == cb.capacity - 1) {
//             // Handle buffer full
//             printf("Buffer full\n");
//             break;
//         }
//         cb.buffer[cb.tail] = sampleData[i];
//         cb.tail = (cb.tail + 1) % cb.capacity;
//         cb.count++;
//     }

//     // Extract lines from the circular buffer
//     char *line;
//     while ((line = extractLine(&cb)) != NULL) {
//         printf("Extracted Line: %s\n", line);
//         free(line); // Don't forget to free the allocated memory
//     }

//     // Free the buffer memory
//     free(cb.buffer);

//     return 0;
// }
