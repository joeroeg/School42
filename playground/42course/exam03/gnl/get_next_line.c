#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 10
# endif

char *ft_strchr(const char *s, int c) {
    while (*s != (char)c)
        if (!*s++) return (NULL);
    return (char *)s;
}

int ft_strlen(const char *s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

char *ft_strdup(const char *str) {
    size_t i = 0;
    char *s;
    i = ft_strlen(str);
    s = (char *)malloc(sizeof(char) * (i + 1));
    if (s == NULL) return (NULL);
    for (size_t j = 0; j <= i; j++) s[j] = str[j];
    return s;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;
    substr = (char *)malloc(len + 1);
    if (!substr) return (NULL);
    for (i = 0; i < len; i++) substr[i] = s[start + i];
    substr[i] = '\0';
    return substr;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t i, j;
    size_t len1 = 0, len2 = 0;
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = (char *)malloc(len1 + len2 + 1);
    if (!str) return (NULL);
    for (i = 0; i < len1; i++) str[i] = s1[i];
    for (j = 0; j < len2; j++) str[i + j] = s2[j];
    str[i + j] = '\0';
    return str;
}

void free_buffer(char **ptr) {
    if (ptr && *ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

// char *extract_line(char **static_buffer)
// {
//     char *newline = ft_strchr(*static_buffer, '\n');
//     char *output_line;
//     char *new_static_buffer;
//     if (!newline)
//     {
//         if (**static_buffer == '\0')
//             free_buffer(static_buffer); return (NULL);
//         output_line = ft_strdup(*static_buffer);
//         free_buffer(static_buffer);
//         return (output_line);
//     }
//     else
//     {
//         output_line = ft_substr(*static_buffer, 0, newline - *static_buffer + 1);
//         new_static_buffer = ft_strdup(newline + 1);
//         free_buffer(static_buffer);
//         *static_buffer = new_static_buffer;
//         return (output_line);
//     }
// }

char *extract_line(char **buffer) {
    char *newline_position = ft_strchr(*buffer, '\n');
    char *line = NULL;
    char *new_buffer = NULL;

    // If no newline is found, return the whole buffer (could be the last line)
    if (!newline_position) {
        if (**buffer == '\0') {
            // Buffer is empty, nothing to extract
            free_buffer(buffer);
            return NULL;
        }
        line = ft_strdup(*buffer); // Duplicate the whole buffer as a line
        free_buffer(buffer); // Clear the buffer after extracting the line
    } else {
        // Calculate the length of the line including the newline character
        size_t line_length = newline_position - *buffer + 1;
        line = ft_substr(*buffer, 0, line_length); // Extract the line including the newline

        // Prepare the remaining buffer for the next call
        size_t new_buffer_start = line_length;
        size_t remaining_length = ft_strlen(*buffer) - new_buffer_start;
        if (remaining_length > 0) {
            new_buffer = ft_substr(*buffer, new_buffer_start, remaining_length);
        }

        free_buffer(buffer); // Free the old buffer
        *buffer = new_buffer; // Assign the remaining content to the buffer
    }

    return line;
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
            break;
        read_buffer[read_length] = '\0';
        char *temp = ft_strjoin(static_buffer[fd], read_buffer);
        free_buffer(&static_buffer[fd]);
        static_buffer[fd] = temp;
    }
    return extract_line(&static_buffer[fd]);
}

int main(void) {
    int fd = open("output_file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
