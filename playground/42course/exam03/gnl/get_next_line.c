#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char *extract_line(char **static_buffer)
{
    char *newline_pos = strchr(*static_buffer, '\n');
    char *line = NULL;
    char *temp = NULL;
    size_t line_len = 0;

    if (newline_pos != NULL)
    {
        line_len = newline_pos - *static_buffer + 1;
        line = malloc(line_len + 1);
        if (!line)
        {
            free (*static_buffer);
            return NULL;
        }
        strncpy(line, *static_buffer, line_len);
        line[line_len] = '\0';
        temp = strdup(newline_pos + 1);
        free (*static_buffer);
        *static_buffer = temp;
    }
    return line;
}

char *get_next_line(int fd)
{
    static char *static_buffer = NULL;
    char        read_buffer[BUFFER_SIZE + 1] = {0};
    int         read_bytes = 0;
    char        *temp = NULL;
    char        *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0) return NULL;

    if (!static_buffer)
    {
        static_buffer = malloc(1);
        if (!static_buffer) return NULL;
        static_buffer[0] = '\0';
    }
    while (!strchr(static_buffer, '\n'))
    {
        read_bytes = read(fd, read_buffer, BUFFER_SIZE);
        if (read_bytes < 0) return NULL;
        if (read_bytes == 0) break;
        read_buffer[read_bytes] = '\0';
        temp = malloc(read_bytes + strlen(static_buffer) + 1);
        if (!temp) return NULL;
        strcpy(temp, static_buffer);
        strcat(temp, read_buffer);
        free (static_buffer);
        static_buffer = temp;
    }

    line = extract_line(&static_buffer);
    if (read_bytes <= 0 && static_buffer)
    {
        free (static_buffer);
        static_buffer = NULL;
    }
    return line;
}
