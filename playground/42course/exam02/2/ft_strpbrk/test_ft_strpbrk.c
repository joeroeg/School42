#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    char *result = ft_strpbrk(argv[1], argv[2]);

    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("NULL\n");
    }

    return 0;
}
