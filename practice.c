#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define MAX_CHUNKS 1024
#define CHUNK_SIZE 512

char *chunks[MAX_CHUNKS];

// Function to read a chunk of data
ssize_t read_chunk(int fd, char **chunk) {
    *chunk = malloc(CHUNK_SIZE);
    if (!*chunk) return -1; // Allocation failed
    return read(fd, *chunk, CHUNK_SIZE);
}

// Function to free chunks
void free_chunks() {
    for (int i = 0; i < MAX_CHUNKS; ++i) {
        free(chunks[i]);
        chunks[i] = NULL;
    }
}

// Function to find a newline in a chunk
int find_newline(char *chunk, int start, int length) {
    for (int i = start; i < length; ++i) {
        if (chunk[i] == '\n') return i;
    }
    return -1;
}

// Function to get the next line
char *get_next_line(int fd) {
    static int current_chunk = 0;
    static int offset = 0;
    char *line = NULL;
    int line_length = 0;

    while (current_chunk < MAX_CHUNKS) {
        if (chunks[current_chunk] == NULL) {
            ssize_t bytesRead = read_chunk(fd, &chunks[current_chunk]);
            if (bytesRead <= 0) break; // End of file or error
        }

		int newline_index = find_newline(chunks[current_chunk], offset, CHUNK_SIZE);
        int to_copy;

		if (newline_index != -1) {
            to_copy = newline_index - offset + 1; // Include newline
        } else {
            to_copy = CHUNK_SIZE - offset;
        }

        line = realloc(line, line_length + to_copy + 1);
        if (!line) {
            free_chunks();
            return NULL; // Allocation error
        }

        memcpy(line + line_length, chunks[current_chunk] + offset, to_copy);
        line_length += to_copy;

		if (newline_index != -1) {
            offset = newline_index + 1;
            if (offset >= CHUNK_SIZE) {
                offset = 0;
                current_chunk++;
            }
            line[line_length] = '\0'; // Replace newline with null terminator
            return line;
        } else {
            offset = 0;
            current_chunk++;
        }
    }

    free_chunks();
    return line_length > 0 ? line : NULL;
}

// Main function for testing
int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    // Close the file descriptor
    return 0;
}
