#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n) {
    const unsigned char *source;
    unsigned char character;
    size_t i;

    source = s;
    character = (unsigned char)c;
    i = 0;
    while (i < n) {
        if (source[i] == character)
            return ((void *)(source + i));
        i++;
    }
    return (NULL);
}

char *ft_strchr(const char *s, int c) {
    while (*s && c != *s)
        s++;
    if (*s == c)
        return ((char *)s);
    return (0);
}

int main() {
    const char *str = "Hello, World!";
    int character = '\0';

    // Using ft_memchr on a null-terminated string
    void *result = ft_memchr(str, character, strlen(str));

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", character, (char *)result - str);
    } else {
        printf("Character '%c' not found in the string.\n", character);
    }

    return 0;
}