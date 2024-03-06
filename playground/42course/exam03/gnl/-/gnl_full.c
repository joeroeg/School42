#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

char	*ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);

    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*temporary_ptr;

	if (!s)
		return (0);
	temporary_ptr = s;
	while (*s)
		s++;
	return (s - temporary_ptr);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen(str) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = str[i];
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (NULL);
	if (start + len > str_len)
		len = str_len - start;
	substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

void free_buffer(char **ptr)
{
    if (*ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

char *extract_line(char **static_buffer)
{
    char *newline = ft_strchr(*static_buffer, '\n');
    char *output_line;
    char *new_static_buffer;

    if (!newline) // No newline found, return the whole buffer
    {
        if (**static_buffer == '\0') // Buffer is empty
        {
            free_buffer(static_buffer);
            return (NULL);
        }
        output_line = ft_strdup(*static_buffer);
        free_buffer(static_buffer);
        return (output_line);
    }
    else // Newline found, split the buffer
    {
        // +1 to include the newline in the output line, then add a null terminator
        output_line = ft_substr(*static_buffer, 0, newline - *static_buffer + 1);
        // Create a new buffer starting from the character after the newline
        new_static_buffer = ft_strdup(newline + 1);
        free_buffer(static_buffer); // Free the old buffer
        *static_buffer = new_static_buffer; // Assign the new buffer
        return (output_line);
    }
}

char *get_next_line(int fd)
{
    static char *static_buffer[MAX_FD];
    char read_buffer[BUFFER_SIZE + 1];
    ssize_t read_length;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD) return (NULL);

    if (!static_buffer[fd])
    {
        static_buffer[fd] = malloc(1);
        if (!static_buffer[fd])
            return (NULL);
        static_buffer[fd][0] = '\0';
    }
    while (!ft_strchr(static_buffer[fd], '\n'))
    {
        read_length = read(fd, read_buffer, BUFFER_SIZE);
        if (read_length <= 0)
            break; // EOF or error
        read_buffer[read_length] = '\0';
        char *temp = ft_strjoin(static_buffer[fd], read_buffer);
        free_buffer(&static_buffer[fd]);
        static_buffer[fd] = temp;
    }
    return extract_line(&static_buffer[fd]);
}

int main(void) {
    int fd = open("file1.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); // Free each line after use
    }
    close(fd);
    return 0;
}

