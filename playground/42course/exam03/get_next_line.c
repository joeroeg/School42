#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef MAX_FD
#define MAX_FD 128
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

char *extract_line(char **buffer)
{
	char	*line = NULL;
	char	*newline_pos = strchr(*buffer,'\n');
	size_t	newline_len = 0;

	if (newline_pos != NULL)
	{
		newline_len = newline_pos - *buffer + 1;
		line = malloc(newline_len + 1);
		strncpy(line, *buffer, newline_len);
		line[newline_len] = '\0';
		char *temp = strdup(newline_pos + 1);
		free_buffer(buffer);
		*buffer = temp;
	}
	return line;
}

char *gnl(int fd)
{
	static char *buffer[MAX_FD];
	char		read_buffer[BUFFER_SIZE + 1];
	size_t		buffer_len;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0) return NULL;

	if (!buffer[fd])
	{
		buffer[fd] = malloc(1);
		buffer[fd][0] = '\0';
	}
	while (!strchr(buffer[fd], '\n'))
	{
		buffer_len = read(fd, read_buffer, BUFFER_SIZE);
		read_buffer[buffer_len] = '\0';
		if (buffer_len < 0) return NULL;
		if (buffer_len == 0) break;
		int len2 = strlen(buffer[fd]);
		int len1 = strlen(read_buffer);
		char *temp = malloc(len1 + len2 + 1);
		strcpy(temp, buffer[fd]);
		strcat(temp, read_buffer);
		free_buffer(&buffer[fd]);
		buffer[fd] = temp;
	}
	return (extract_line(&buffer[fd]));
}


int main()
{
	int fd = open("file1.txt", O_RDONLY);
	char *line = NULL;
	while ((line = gnl(fd)))
	{
		printf("%s", line);
		free (line);
	}
	close (fd);
}
