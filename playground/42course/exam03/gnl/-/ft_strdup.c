#include <stdlib.h> // For malloc

char *ft_strdup(const char *str) {
    size_t i = 0;
    char *s;

    // First pass to calculate the length of str
    while (str[i] != '\0') i++;

    // Allocate memory for the duplicate string, including space for '\0'
    s = (char *)malloc(sizeof(char) * (i + 1));
    if (s == NULL) return (NULL);

    // Copy the string into the newly allocated memory
    for (size_t j = 0; j <= i; j++) {
        s[j] = str[j];
    }

    return s;
}

int main(void) {
    char const *str = "Hello, World!";
    char *dup = ft_strdup(str);
    return 0;
}
