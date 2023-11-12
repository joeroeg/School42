#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE + 1];
    static int i = 0;
    static int read_bytes = 0;
    char *line = malloc(BUFFER_SIZE + 1);
    if (!line) return NULL; // Check malloc failure

    int j = 0;
    while (1) {
        if (i >= read_bytes) {
            read_bytes = read(fd, buffer, BUFFER_SIZE);
            if (read_bytes <= 0) { // EOF or error
                free(line);
                return NULL;
            }
            i = 0;
        }

        line[j++] = buffer[i++];
        if (j >= BUFFER_SIZE || buffer[i - 1] == '\n') {
            line[j] = '\0';
            break;
        }
    }

    return line;
}

int main() {
    const char *path = "test.txt";
    char *line;
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
