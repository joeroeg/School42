#include <stdio.h>
#include <stdlib.h>	 // For dynamic memory allocation
#include <fcntl.h>   // For open
#include <unistd.h>  // For read and close
#include <stdlib.h>  // For malloc, free
#include <string.h>  // For memcpy
#include <stdbool.h> // For bool type

typedef struct CircularBuffer
{
    char	*buffer;
    size_t	capacity;
    size_t	head;
    size_t	tail;
    size_t	count;
} CircularBuffer;

void initCircularBuffer(CircularBuffer *cb, size_t capacity) {
    cb->buffer = malloc(capacity);
    cb->capacity = capacity;
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

void freeCircularBuffer(CircularBuffer *cb) {
    free(cb->buffer);
}

void expandBuffer(CircularBuffer *cb) {
    int newCapacity = cb->capacity * 2;  // Double the capacity
    char *newBuffer = realloc(cb->buffer, newCapacity * sizeof(char));
    if (newBuffer == NULL) {
        perror("Failed to expand buffer");
        exit(EXIT_FAILURE);
    }

    // Adjust the buffer if the data was wrapped around
    if (cb->tail < cb->head) {
        memcpy(newBuffer + cb->capacity, newBuffer, cb->tail * sizeof(char));
        cb->tail += cb->capacity;
    }

    cb->buffer = newBuffer;
    cb->capacity = newCapacity;
}

int isBufferFull(CircularBuffer *cb) {
    return cb->count == cb->capacity;
}

int readLine(int fd, CircularBuffer *cb, char *line, size_t lineCapacity) {
    char ch;
    ssize_t bytesRead;
    size_t lineLength = 0;
	int isNewLineRead = 0;

    while ((bytesRead = read(fd, &ch, 1)) > 0 && lineLength < lineCapacity - 1) {
		if (isBufferFull(cb)) {
        expandBuffer(cb);
    }
        if (cb->count < cb->capacity) {
            cb->buffer[cb->tail] = ch;
            cb->tail = (cb->tail + 1) % cb->capacity;
            cb->count++;
        }
		// so as I understand we do not need to check if the buffer is full because we are expanding it.
		// else {
        //     // Process the character at the head if the buffer is full
        //     if (lineLength < lineCapacity - 1) {
        //         line[lineLength++] = cb->buffer[cb->head];
        //     }
        //     cb->buffer[cb->head] = ch;
        //     cb->head = (cb->head + 1) % cb->capacity;
        // }

        if (ch == '\n') {
            isNewLineRead = 1;
        }
    }

    if (bytesRead == -1) {
        // Handle read error
        perror("Read error");
        return -1;
    }

    while (cb->count > 0 && lineLength < lineCapacity - 1) {
        line[lineLength++] = cb->buffer[cb->head];
        cb->head = (cb->head + 1) % cb->capacity;
        cb->count--;
    }

    line[lineLength] = '\0';
    return lineLength;
}

int main() {
    CircularBuffer cb;
    initCircularBuffer(&cb, 100); // 100 is the buffer capacity

    int fileDescriptor = open("example.txt", O_RDONLY);
    if (fileDescriptor < 0) {
        perror("Unable to open file");
        return 1;
    }

    char line[101]; // Assuming max line length of 100
    while (readLine(fileDescriptor, &cb, line, sizeof(line))) {
        printf("%s", line);
    }

    close(fileDescriptor);
    freeCircularBuffer(&cb);
    return 0;
}

