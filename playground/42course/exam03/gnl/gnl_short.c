#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
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
    s = (char *)malloc(sizeof(char) * (i + 1)); // Allocate memory for the duplicate string, including space for '\0'
    if (s == NULL) return (NULL);
    for (size_t j = 0; j <= i; j++) s[j] = str[j]; // Copy the string into the newly allocated memory
    return s;
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;
    substr = (char *)malloc(len + 1); // Allocate memory for the substring + null terminator
    if (!substr) return (NULL); // Basic check for allocation failure
    for (i = 0; i < len; i++) substr[i] = s[start + i]; // Copy characters to form the substring
    substr[i] = '\0'; // Null-terminate the substring
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
    for (i = 0; i < len1; i++) str[i] = s1[i]; // Copy s1 to str
    for (j = 0; j < len2; j++) str[i + j] = s2[j]; // Concatenate s2 to str
    str[i + j] = '\0'; // Null-terminate the concatenated string
    return str;
}

void free_buffer(char **ptr) {
    if (ptr && *ptr) {
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
            free_buffer(static_buffer); return (NULL);
        output_line = ft_strdup(*static_buffer);
        free_buffer(static_buffer);
        return (output_line);
    }
    else // Newline found, split the buffer
    {
        output_line = ft_substr(*static_buffer, 0, newline - *static_buffer + 1); // +1 to include the newline in the output line, then add a null terminator
        new_static_buffer = ft_strdup(newline + 1); // Create a new buffer starting from the character after the newline
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
    const char* command = "for i in {1..5}; do echo \"file 1 line $i\"; done > file1.txt";
    int return_value = system(command);
    int fd = open("file1.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); // Free each line after use
    }
    close(fd);
    const char* filename = "file1.txt";
    remove(filename);
    return 0;
}
