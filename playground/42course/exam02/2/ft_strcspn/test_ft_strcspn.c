#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: test_ft_strcspn string reject_set\n");
        return 1;
    }

    size_t result = ft_strcspn(argv[1], argv[2]);
    printf("%zu", result);

    return 0;
}
