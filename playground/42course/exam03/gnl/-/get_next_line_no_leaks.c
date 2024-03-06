#include "get_next_line.h"

static char *read_to_static_buffer(int fd, char *static_buf);
static char *extract_line_from_buffer(char **static_buf);
static char *append_buffer(char *line, char *buffer, int n);

char *get_next_line(int fd)
{
    static char *static_buf = NULL; // Static buffer to hold data between calls
    char read_buf[BUFFER_SIZE + 1]; // Temporary buffer for read()
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    static_buf = read_to_static_buffer(fd, static_buf);
    if (!static_buf)
        return NULL;

    char *line = extract_line_from_buffer(&static_buf);
    return line;
}

static char *read_to_static_buffer(int fd, char *static_buf)
{
    char read_buf[BUFFER_SIZE + 1];
    int bytes_read;

    while ((bytes_read = read(fd, read_buf, BUFFER_SIZE)) > 0)
    {
        read_buf[bytes_read] = '\0';
        static_buf = append_buffer(static_buf, read_buf, bytes_read);
        if (strchr(read_buf, '\n'))
            break;
    }

    if (bytes_read < 0)
    {
        free(static_buf);
        return NULL;
    }

    return static_buf;
}

static char *extract_line_from_buffer(char **static_buf)
{
    char *line_end, *line, *new_buf;
    if (!(line_end = strchr(*static_buf, '\n')))
        line_end = strchr(*static_buf, '\0');

    int line_length = line_end - *static_buf + (*line_end == '\n' ? 1 : 0);
    line = (char *)malloc(sizeof(char) * (line_length + 1));
    if (!line)
        return NULL;

    strncpy(line, *static_buf, line_length);
    line[line_length] = '\0';

    if (line_length < strlen(*static_buf))
    {
        new_buf = strdup(*static_buf + line_length);
        free(*static_buf);
        *static_buf = new_buf;
    }
    else
    {
        free(*static_buf);
        *static_buf = NULL;
    }

    return line;
}

static char *append_buffer(char *line, char *buffer, int n)
{
    char *new_line;
    int current_len = line ? strlen(line) : 0;
    new_line = (char *)malloc(sizeof(char) * (current_len + n + 1));
    if (!new_line)
        return NULL;

    if (line)
    {
        strcpy(new_line, line);
        free(line);
    }

    strncpy(new_line + current_len, buffer, n);
    new_line[current_len + n] = '\0';

    return new_line;
}

int main()
{
	int fd = open("file1.txt", O_RDONLY);
	char *line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free (line);
	}
	close (fd);
}
