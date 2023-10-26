#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static size_t ft_countword(char const *s, char c) {
    size_t count = 0;

    while (*s) {
        while (*s == c)
            s++;
        if (*s) {
            count++;
            while (*s && *s != c)
                s++;
        }
    }

    return count;
}

char **ft_split(char const *s, char c) {
    if (!s)
        return NULL;

    char **lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
    if (!lst)
        return NULL;

    int i = 0;
    while (*s) {
        while (*s == c && *s)
            s++;
        if (*s) {
            const char *word_start = s;
            while (*s && *s != c)
                s++;
            size_t word_len = s - word_start;
            lst[i] = (char *)malloc(word_len + 1);
            if (!lst[i]) {
                return NULL;
            }
            strncpy(lst[i], word_start, word_len);
            lst[i][word_len] = '\0';
            i++;
        }
    }

    lst[i] = NULL;
    return lst;
}

int main() {
    char *str = "abc def ghi";
    char **split = ft_split(str, ' ');
    for (int i = 0; split[i]; i++) {
        printf("%s\n", split[i]);
    }
    return 0;
}
