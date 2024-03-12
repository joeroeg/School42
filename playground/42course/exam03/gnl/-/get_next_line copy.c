#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

char *ft_strchr(char *s, char c)
{
    while (*s != c)
    {
        if (*s == '\0') return NULL;
        s++;
    }
    return s;
}

void ft_strcpy(char *s1, char *s2)
{
    while ((*s1++ = *s2++));
}

void ft_strcat(char *s1, char *s2)
{
    while ((*s1)) s1++;
    while ((*s1++ = *s2++));
}

void ft_strncpy(char *s1, char *s2, size_t n)
{
    size_t i = 0;
    for (; i < n; i++) *s1++ = *s2++;
    for (; *s1; i++) *s1 = '\0';
}


void *ft_strdup(char *s)
{
    char *dup = NULL;
    int len = ft_strlen(s);
    dup = malloc(len + 1);
    dup[len] = '\0';
    ft_strcpy(dup, s);
    return dup;
}

char *extract_line(char **sb)
{
    char *newline_pos = ft_strchr(*sb, '\n');
    char *line = NULL;
    char *temp = NULL;
    size_t newline_len = 0;

    if (newline_pos)
    {
        newline_len = newline_pos - *sb + 1;
        line = malloc(newline_len + 1);
        strncpy(line, *sb, newline_len);
        line[newline_len] = '\0';
        temp = ft_strdup(newline_pos + 1);
        free (*sb);
        *sb = temp;
    }
    else if (ft_strlen(*sb) > 0)
    {
        line = ft_strdup(*sb);
        free(*sb);
        *sb = NULL;
    }
    return line;
}

char *get_next_line(int fd)
{
    static char *sb = NULL;
    char read_buffer[BUFFER_SIZE + 1];
    int read_bytes = 0;
    char *temp = NULL;

    if (!sb)
    {
        sb = malloc(1);
        if (!sb) return NULL; // Ensure memory was allocated
        *sb = '\0';
    }

    while (!ft_strchr(sb, '\n'))
    {
        read_bytes = read(fd, read_buffer, BUFFER_SIZE);
        if (read_bytes == 0 && ft_strlen(sb) == 0)
        {
            free(sb);
            sb = NULL;
            return NULL;
        }
        if (read_bytes < 0) return NULL;
        if (read_bytes == 0) break;
        read_buffer[read_bytes] = '\0';
        temp = malloc(ft_strlen(sb) + read_bytes + 1);
        if (!temp) return NULL; // Ensure memory was allocated

        ft_strcpy(temp, sb);
        ft_strcat(temp, read_buffer);
        free(sb);
        sb = temp;
    }
    char *line = extract_line(&sb);
    return line;
}

int main()
{
	// int fd = open("../test", O_RDONLY);
    int fd = open("in", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}
