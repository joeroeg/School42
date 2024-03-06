#include <fcntl.h> // open
#include <stdio.h> // printf
#include <stdlib.h> // malloc, NULL
#include <string.h> // strchr, strcpy, strcat, strncpy, strdup
#include <unistd.h> // read

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

void ft_strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));
}

void ft_strcat(char *dest, const char *src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}

void ft_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    for ( ; i < n; i++) {
        dest[i] = '\0';
    }
}

char *ft_strchr(const char *s, int c) {
    while (*s != (char)c) if (!*s++) return NULL;
    return (char *)s;
}

char *ft_strdup(const char *s) {
    char *d = malloc(strlen(s) + 1);  // Allocate memory for the duplicate string
    if (d == NULL) return NULL;       // Check if memory allocation failed
    ft_strcpy(d, s);                     // Copy the string into the newly allocated memory
    return d;
}


/**
 * 1. Find length of you line and allocate memory.
 * 2. Copy from sb to line calculated length and null terminate.
 * 3. Duplicate the remaining data into a temporary variable and point sb to it.
 * 4. Add case when no newline is found by duplicating sb to line
*/
char *extract_line(char **sb)
{
	char	*line = NULL;
	char	*newline_pos = ft_strchr(*sb, '\n');
	char	*temp = NULL;
	size_t	line_len;

	if (newline_pos != NULL)
	{
		line_len = newline_pos - *sb + 1;
		line = malloc(line_len + 1);
		ft_strncpy(line, *sb, line_len);
		line[line_len] = '\0';
		temp = ft_strdup(newline_pos + 1);
		free_buffer(sb);
		*sb = temp;
	}
	return line;
}

/**
 * 1. allocate 1 byte for sb
 * 2. while you cannot find newline read n number of bytes from fd
 * 3. copy static buffer to temp
 * 4. concatenate read buffer to temp
 * 5. point static buffer to temp
*/
char *get_next_line(int fd)
{
	static char *static_buffer[MAX_FD];
	char		read_buffer[BUFFER_SIZE + 1] = {0};
	int			read_len;
	char		*temp = NULL;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0) return NULL;
	if (!static_buffer[fd])
	{
		static_buffer[fd] = malloc(1);
		if (!static_buffer[fd]) return NULL;
		static_buffer[fd][0] = '\0';
	}
	while (!ft_strchr(static_buffer[fd], '\n'))
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		if (read_len <= 0) break;
		temp = malloc(read_len + strlen(static_buffer[fd]) + 1);
		ft_strcpy(temp, static_buffer[fd]);
		ft_strcat(temp, read_buffer);
		free_buffer(&static_buffer[fd]);
		static_buffer[fd] = temp;
	}
	return (extract_line(&static_buffer[fd]));
}

int main()
{
	int fd = open("file1.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}
