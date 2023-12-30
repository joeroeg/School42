#include <stdio.h>
#include <string.h>

char** tokenize_path(const char* path) {
    int count = 1; // Start with 1 for the first token
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == ':') {
            count++;
        }
    }

    // Allocate memory for array of strings
    char** dirs = malloc((count + 1) * sizeof(char*)); // +1 for NULL terminator
    if (dirs == NULL) {
        perror("malloc");
        return NULL;
    }

    // Duplicate the path to avoid modifying the original string
    char* path_dup = strdup(path);
    if (path_dup == NULL) {
        free(dirs);
        perror("strdup");
        return NULL;
    }

    // Tokenize the path
    char* token = strtok(path_dup, ":");
    int index = 0;
    while (token != NULL) {
        dirs[index] = strdup(token);
        if (dirs[index] == NULL) {
            // Clean up in case of allocation failure
            for (int j = 0; j < index; j++) {
                free(dirs[j]);
            }
            free(dirs);
            free(path_dup);
            perror("strdup");
            return NULL;
        }
        index++;
        token = strtok(NULL, ":");
    }
    dirs[index] = NULL; // NULL-terminate the array

    // Clean up
    free(path_dup);

    return dirs;
}

const char* find_path_env(char* const envp[]) {
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            return envp[i] + 5;  // Skip the "PATH=" part
        }
    }
    return NULL;  // Return NULL if PATH is not found
}

int main() {
    // Example environment variables
    char* envp[] = {
        "USER=zhukov",
        "PATH=/usr/bin:/bin:/usr/local/bin",
        "ANOTHERVAR=othervalue",
        NULL
    };

    const char* path = find_path_env(envp);
    printf("Found PATH: %s\n", path);
    return 0;
}
