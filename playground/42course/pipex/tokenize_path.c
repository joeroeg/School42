#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error_message(const char *msg, int code) {
    // Error handling function
    perror(msg);
    exit(code);
}

char **tokenize_path(const char *path) {
    int token_count = 1, index = 0;
    char **token_array, *str_copy, *token;

    // Counting tokens
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == ':')
            token_count++;
    }

    // Allocating token array
    token_array = malloc((token_count + 1) * sizeof(char *));
    if (token_array == NULL) {
        error_message("malloc", 1);
        return NULL;
    }

    // Tokenizing
    str_copy = strdup(path);
    if (str_copy == NULL) {
        free(token_array);
        error_message("strdup", 1);
        return NULL;
    }

    token = strtok(str_copy, ":");
    while (token != NULL) {
        token_array[index] = strdup(token);
        if (token_array[index] == NULL) {
            for (int j = 0; j < index; j++) {
                free(token_array[j]);
            }
            free(token_array);
            free(str_copy);
            error_message("strdup", 1);
            return NULL;
        }
        index++;
        token = strtok(NULL, ":");
    }
    token_array[index] = NULL;
    free(str_copy);
    return token_array;
}

int main() {
    // Sample path string for testing
    const char *sample_path = "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin";

    // Tokenize the sample path
    char **tokens = tokenize_path(sample_path);

    // Check if tokenization was successful
    if (tokens == NULL) {
        fprintf(stderr, "Failed to tokenize path.\n");
        return 1;
    }

    // Print the tokens
    printf("Tokens from the path:\n");
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%d: %s\n", i, tokens[i]);
    }

    // Free the memory allocated for the tokens
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}
