#include <stdlib.h> // For malloc and free
#include <stdio.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    size_t i, j;

    size_t len1 = 0, len2 = 0;
    while (s1 && s1[len1]) len1++;
    while (s2 && s2[len2]) len2++;
    str = (char *)malloc(len1 + len2 + 1);
    if (!str) return (NULL);
    for (i = 0; i < len1; i++) str[i] = s1[i]; // Copy s1 to str
    for (j = 0; j < len2; j++) str[i + j] = s2[j]; // Concatenate s2 to str
    str[i + j] = '\0'; // Null-terminate the concatenated string
    return str;
}


int main(void)
{
    char const *s1 = "Hello, ";
    char const *s2 = "World!";
    char *str = ft_strjoin(s1, s2);
    printf("Joined string: '%s'\n", str);
    free(str);
    return 0;
}
