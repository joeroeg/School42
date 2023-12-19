#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s 'string to split'\n", argv[0]);
        return 1;
    }

    char **words = ft_split(argv[1]);
    if (!words) {
        fprintf(stderr, "ft_split returned NULL\n");
        return 1;
    }

    for (int i = 0; words[i] != NULL; i++) {
        printf("'%s'\n", words[i]);
        free(words[i]);  // Assuming each word is dynamically allocated
    }
    free(words);  // Assuming the array itself is dynamically allocated

    return 0;
}
