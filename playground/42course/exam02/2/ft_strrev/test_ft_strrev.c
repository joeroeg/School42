#include <stdio.h>

char *ft_strrev(char *str);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s string_to_reverse\n", argv[0]);
        return 1;
    }

    char *result = ft_strrev(argv[1]);
    printf("%s\n", result);

    return 0;
}
