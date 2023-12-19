#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: test_ft_itoa number\n");
        return 1;
    }

    int nbr = atoi(argv[1]);
    char *result = ft_itoa(nbr);

    if (result) {
        printf("%s", result);
        free(result);
    }

    return 0;
}
