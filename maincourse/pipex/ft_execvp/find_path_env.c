#include <stdio.h>
#include <string.h>
#include <assert.h>

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
        "OTHERVAR=somevalue",
        "PATH=/usr/bin:/bin:/usr/local/bin",
        "ANOTHERVAR=othervalue",
        NULL
    };

    const char* path = find_path_env(envp);
    printf("Found PATH: %s\n", path);

    // // Assert that the function correctly finds the PATH
    // assert(path != NULL && strcmp(path, "/usr/bin:/bin:/usr/local/bin") == 0);

    // printf("Test passed.\n");
    return 0;
}
