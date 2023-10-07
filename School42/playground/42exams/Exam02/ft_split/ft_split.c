#include <stdlib.h>
#include <string.h>

static size_t count_words(const char *str, char delimiter) {
    size_t count = 0;
    int in_word = 0;

    while (*str) {
        if (*str == delimiter) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }

    return count;
}

static char *strdup_substring(const char *str, char delimiter) {
    const char *end = str;
    while (*end && *end != delimiter)
        end++;

    size_t len = end - str;
    char *sub = (char *)malloc((len + 1) * sizeof(char));
    if (sub == NULL)
        return NULL;

    memcpy(sub, str, len);
    sub[len] = '\0';
    return sub;
}

char **ft_split(const char *s, char c) {
    if (!s)
        return NULL;

    size_t word_count = count_words(s, c);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (result == NULL)
        return NULL;

    size_t index = 0;
    while (*s) {
        if (*s == c) {
            s++;
            continue;
        }

        result[index] = strdup_substring(s, c);
        if (result[index] == NULL) {
            while (index > 0) {
                free(result[--index]);
            }
            free(result);
            return NULL;
        }

        index++;
        while (*s && *s != c)
            s++;
    }

    result[index] = NULL;
    return result;
}

#include <stdio.h>

int main() {
    const char *str1 = "hello,world,how,are,you";
    const char *str2 = "apples,oranges,bananas";
    const char *str3 = "one,two,,four";
    char **result1 = ft_split(str1, ',');
    char **result2 = ft_split(str2, ',');
    char **result3 = ft_split(str3, ',');

    // Print the results
    printf("Result 1:\n");
    for (int i = 0; result1[i] != NULL; i++) {
        printf("%s\n", result1[i]);
        free(result1[i]);
    }
    free(result1);

    printf("\nResult 2:\n");
    for (int i = 0; result2[i] != NULL; i++) {
        printf("%s\n", result2[i]);
        free(result2[i]);
    }
    free(result2);

    printf("\nResult 3:\n");
    for (int i = 0; result3[i] != NULL; i++) {
        printf("%s\n", result3[i]);
        free(result3[i]);
    }
    free(result3);

    return 0;
}
