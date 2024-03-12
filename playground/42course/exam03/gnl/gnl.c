#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

char *extract_line(char **static_buffer)
{
	char	*newline_pos = strchr(*static_buffer, '\n');
	size_t	line_len = 0;
	char	*line = NULL;
	char	*temp = NULL;

	if (newline_pos)
	{
		line_len = newline_pos - *static_buffer + 1;
		line = malloc(line_len + 1);
		strncpy(line, *static_buffer, line_len);
		line[line_len] = '\0';
		temp = strdup(newline_pos + 1);
		free (*static_buffer);
		*static_buffer = temp;
	}
	else if (strlen(*static_buffer))
	{
		line = strdup(*static_buffer);
		free (*static_buffer);
		*static_buffer = NULL;
	}
	return line;
}

char *get_next_line(int fd)
{
    static char *sb = NULL;
    char        read_buffer[BUFFER_SIZE] = {0};
    int         read_bytes = 0;
    char        *line = NULL;
    char        *temp = NULL;

    if (!sb)
    {
        sb = malloc(1);
        sb[0] = '\0';
    }
    while (!strchr(sb, '\n'))
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes < 0) return NULL;
		if (read_bytes == 0 && strlen(sb) == 0)
		{
			free(sb);
			sb = NULL;
			return NULL;
		}
		if (read_bytes == 0) break;
		read_buffer[read_bytes] = '\0';
		int len1 = strlen(sb);
		int len2 = strlen(read_buffer);
		temp = malloc(len1 + len2 + 1);
		strcpy(temp, sb);
		strcat(temp, read_buffer);
		free (sb);
		sb = temp;
	}
    line = extract_line(&sb);
    return line;
}

int main()
{
    int     fd = open("test", O_RDONLY);
    char    *line = NULL;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free (line);
    }
}
