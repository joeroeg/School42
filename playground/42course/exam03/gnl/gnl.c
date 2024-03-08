#include "get_next_line.h"

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
    char *d = malloc(strlen(s) + 1);
    if (d == NULL) return NULL;
    ft_strcpy(d, s);
    return d;
}

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
		free(*sb);
		*sb = temp;
	}
	return line;
}

char *get_next_line(int fd)
{
	static char *static_buffer = NULL;
	char		read_buffer[BUFFER_SIZE + 1] = {0};
	int			read_len = 0;
	char		*temp = NULL;
	char		*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0) return NULL;
	if (!static_buffer)
	{
		static_buffer = malloc(1);
		if (!static_buffer) return NULL;
		static_buffer[0] = '\0';
	}
	while (!ft_strchr(static_buffer, '\n'))
	{
		read_len = read(fd, read_buffer, BUFFER_SIZE);
		if (read_len <= 0) break;
		temp = malloc(read_len + strlen(static_buffer) + 1);
		ft_strcpy(temp, static_buffer);
		ft_strcat(temp, read_buffer);
		free(static_buffer);
		static_buffer = temp;
	}

	line = extract_line(&static_buffer);
	if (read_len <= 0 && static_buffer) { // After last line extraction, check if EOF or read error
        free(static_buffer); // Cleanup static buffer if EOF or read error and no more data to process
        static_buffer = NULL;
    }
	return (line);
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
