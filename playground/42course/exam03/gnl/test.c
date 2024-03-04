#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAX_FD
#define MAX_FD 1024
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

/*
main
    1. what flag to use with open syscall O_RDONLY
    2. how to iterate over a line
    3. I need to free my line variable after each print.

get_next_line
    1. what datatype use with static_buffer
    2. how to read in a buffer
    3. I don't remember what variables I should add
    4.

macros
    1. in macros do not use `=` sign

1. create a file and add lines there
2. open a file for reading
3. create gnl function and add 3 variables
    - static char *static_buffer[MAX_FD]
    - char read_buffer[BUFFER_SIZE + 1]
    - ssize_t read_len;

4. check for invalid input
5. malloc and initialize static buffer (static_buffer[fd][0] = '\0')
6. in a while lopp read buffer size until you find '\n'
7. check if read_len is <= 0 and break

extract newline from a buffer
8.
*/

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i = 0;
    substr = malloc(len + 1);
    for (; i < len; i++) substr[i] = s[start + i];
    substr[i] = 0;
    return substr;
}

void free_buffer(char **ptr)
{
    if (ptr && *ptr)
    {
        free (*ptr);
        *ptr = NULL;
    }
}

char *ft_strjoin(char *s1, char *s2)
{
    ssize_t len1;
    ssize_t len2;
    ssize_t i = 0;
    ssize_t j = 0;
    char *str;
    len1 = strlen(s1);
    len2 = strlen(s2);
    str = (char *)malloc(len1 + len2 + 1);
    if (!str) return NULL;
    for (; i < len1; i++) str[i] = s1[i];
    for (; j < len2; j++) str[i + j] = s2[j];
    str[i + j] = '\0';
    return str;
}

char *ft_strcpy(char *dest, const char *src) {
    char *originalDest = dest; // Save original dest pointer to return it
    while ((*dest++ = *src++)); // Copy src to dest until '\0' is encountered
    return originalDest; // Return the starting address of dest
}

char *ft_strncpy(char *dest, const char *src, size_t n) {
    char *originalDest = dest;
    while (n && (*dest++ = *src++)) { // Copy src to dest until '\0' or n is reached
        n--;
    }
    if (n) { // If n is not 0, this means src was shorter than n, pad with '\0'
        while (--n) *dest++ = '\0';
    }
    return originalDest;
}


char *extract_line(char **buffer) {
    char *line = NULL;
    char *newline = strchr(*buffer, '\n'); // Step 1: Find the newline
    if (newline) {
        size_t line_length = newline - *buffer + 1; // Include the newline
        line = (char *)malloc(line_length + 1); // Allocate space for the line
        if (!line) return NULL;
        ft_strncpy(line, *buffer, line_length); // Copy the line
        line[line_length] = '\0'; // Null-terminate the line

        size_t remaining_length = strlen(*buffer) - line_length;
        char *new_buffer = (char *)malloc(remaining_length + 1); // Allocate space for the remaining buffer
        if (!new_buffer) {
            free(line);
            return NULL;
        }
        ft_strcpy(new_buffer, *buffer + line_length); // Copy the remaining buffer
        free(*buffer); // Free the old buffer
        *buffer = new_buffer; // Update the buffer pointer
    }
    return line; // Return the extracted line
}

char *get_next_line(int fd)
{
    static char *static_buffer[MAX_FD];
    char        read_buffer[BUFFER_SIZE + 1];
    ssize_t     read_len;
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD) return NULL;
    if (!static_buffer[fd])
    {
        static_buffer[fd] = malloc(1);
        if (!static_buffer[fd]) return NULL;
        static_buffer[fd][0] = '\0';
    }
    while (!strchr(static_buffer[fd], '\n'))
    {
        read_len = read(fd, read_buffer, BUFFER_SIZE);
        if (read_len <= 0)
            break;
        read_buffer[read_len] = '\0';
        printf("static buffer: %s\n", static_buffer[fd]);
        printf("  read buffer: %s\n", read_buffer);
        printf("\n");
        char *temp = ft_strjoin(static_buffer[fd], read_buffer);
        free_buffer(&static_buffer[fd]);
        static_buffer[fd] = temp;
    }
    return (extract_line(&static_buffer[fd]));
}

int main()
{
    int fd = open("file1.txt", O_RDONLY);
    char *line = NULL;
    while ((line = get_next_line(fd))) {
        // printf("%s", line);
        free (line);
    }
}
