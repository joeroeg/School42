#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#ifndef MAX_FD
#define MAX_FD 256 // Adjust based on expected limits
#endif

char *get_next_line(int fd) {
    static char *buffer[MAX_FD] = {0};
    char tempBuffer[BUFFER_SIZE + 1];
    ssize_t bytesRead;
    char *temp, *newline;
    size_t len;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
        return NULL;

    if (!buffer[fd]) {
        buffer[fd] = calloc(1, 1); // Initialize as empty string
        if (!buffer[fd]) return NULL;
    }

    while ((bytesRead = read(fd, tempBuffer, BUFFER_SIZE)) > 0) {
        tempBuffer[bytesRead] = '\0';
        len = strlen(buffer[fd]) + bytesRead;
        temp = realloc(buffer[fd], len + 1); // Adjust buffer size
        if (!temp) {
            free(buffer[fd]);
            return NULL;
        }
        buffer[fd] = temp;
        strcat(buffer[fd], tempBuffer); // Append new data
        if (strchr(buffer[fd], '\n')) break; // Newline found
    }

    if (bytesRead < 0 || (bytesRead == 0 && buffer[fd][0] == '\0')) {
        free(buffer[fd]);
        buffer[fd] = NULL;
        return NULL; // Handle read error or EOF with no data
    }

    newline = strchr(buffer[fd], '\n');
    size_t lineLen = newline ? (size_t)(newline - buffer[fd] + 1) : strlen(buffer[fd]);
    char *line = malloc(lineLen + 1);
    if (!line) return NULL;
    strncpy(line, buffer[fd], lineLen);
    line[lineLen] = '\0';

    // Prepare buffer for next call
    temp = newline ? strdup(newline + 1) : calloc(1, 1);
    free(buffer[fd]);
    buffer[fd] = temp;

    return line;
}

int main(void) {
    int fd = open("file1.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); // Free each line after use
    }
    close(fd);
    return 0;
}
