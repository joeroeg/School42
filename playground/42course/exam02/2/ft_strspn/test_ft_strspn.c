#include <stdio.h>

size_t ft_strspn(const char *s, const char *accept);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s string accept\n", argv[0]);
        return 1;
    }

    size_t result = ft_strspn(argv[1], argv[2]);
    printf("%zu\n", result);

    return 0;
}
