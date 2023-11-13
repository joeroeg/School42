#include "get_next_line.h"

char *get_next_line(int fd) {
    static char *static_buffer = NULL;
    char *buffer = malloc(BUFFER_SIZE + 1);
    char *line = NULL;
    ssize_t bytes_read;

    if (fd < 0 || !buffer) {
        free(buffer);
        return NULL;
    }

    while (1) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            free(buffer);
            return NULL; // Error during read
        }

        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            char *temp = ft_strjoin(static_buffer, buffer);
            if (!temp) {
                free(buffer);
                free(static_buffer);
                static_buffer = NULL;
                return NULL;
            }
            free(static_buffer);
            static_buffer = temp;
        }

        // Check if there's a line to extract or if we've reached EOF
        if (ft_strchr(static_buffer, '\n') || (bytes_read == 0 && static_buffer && *static_buffer)) {
            line = extract_line(&static_buffer);
            break;
        }

        // If no bytes were read and no line is available, end the loop
        if (bytes_read == 0) break;
    }

    free(buffer);
    // Free static_buffer if it's empty
    if (static_buffer && *static_buffer == '\0') {
        free(static_buffer);
        static_buffer = NULL;
    }
    return line;
}
