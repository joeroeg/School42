#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


#ifndef MAX_FD
#define MAX_FD 5
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

void free_buffer(char **ptr)
{
	if (ptr && *ptr)
	{
		free (*ptr);
		*ptr = NULL;
	}
}

char *extract_line(char **sb)
{
    char *line = NULL;
    char *temp = NULL;
    char *newline_pos = strchr(*sb, '\n');

    if (newline_pos != NULL)
    {
        size_t line_length = newline_pos - *sb + 1;
        line = (char *)malloc(sizeof(char) * (line_length + 1));
        if (!line) return NULL;
        strncpy(line, *sb, line_length);
        line[line_length] = '\0';

        temp = strdup(newline_pos + 1);
        free_buffer(sb);
        *sb = temp;
    }
    else if (**sb) // No newline found, but buffer is not empty
    {
        line = strdup(*sb);
        free_buffer(sb);
    }
    return line;
}

char *gnl(int fd)
{
	static char *sb[MAX_FD];
	char		read_buffer[BUFFER_SIZE + 1];
	int			read_len;
	char		*temp;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0) return NULL;

	if (!sb[fd])
	{
		sb[fd] = malloc(1);
		if (!sb[fd]) return NULL;
		sb[fd][0] = '\0';
	}
	while (!strchr(sb[fd], '\n'))
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		if (read_len <= 0) break;
		read_buffer[read_len] = '\0';

		size_t len1 = strlen(sb[fd]);
		// size_t len2 = strlen(read_buffer);
		temp = malloc(len1 + read_len + 1);
		if (!temp) return NULL;
		strcpy(temp, sb[fd]);
		strcat(temp, read_buffer);
		free_buffer(&sb[fd]);
		sb[fd] = temp;
	}
	return (extract_line(&sb[fd]));
}

int main()
{
	int fd = open("file1.txt", O_RDONLY);
	char *line;

	while ((line = gnl(fd)))
	{
		printf("%s", line);
		free (line);
	}
	return 0;
}
