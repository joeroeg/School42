#include <stdlib.h>

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
