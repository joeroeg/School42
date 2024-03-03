#include <stdlib.h> // For malloc and free
#include <stdio.h>

// char    *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     char    *substr;
//     size_t  i;
//     size_t  s_len;

//     if (!s) return (NULL);

//     // Calculate the length of s
//     for (s_len = 0; s[s_len] != '\0'; s_len++);

//     // Check if start is beyond the end of s
//     if (start >= s_len) {
//         // Allocate memory for an empty string
//         substr = (char *)malloc(1);
//         if (substr) substr[0] = '\0';
//         return substr;
//     }

//     // Adjust len if it extends beyond the string's end
//     if (start + len > s_len) len = s_len - start;

//     // Allocate memory for the substring
//     substr = (char *)malloc(len + 1);
//     if (!substr) return (NULL);

//     // Copy the substring
//     for (i = 0; i < len; i++) {
//         substr[i] = s[start + i];
//     }

//     // Null-terminate the substring
//     substr[i] = '\0';

//     return substr;
// }

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

int main(void)
{
    char const *s = "Hello, World!";
    unsigned int start = 7;
    size_t len = 5;
    char *substr = ft_substr(s, start, len);
    printf("%s\n", substr);
    free(substr);
    return 0;
}
