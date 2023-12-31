#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your get_path_env function
char *get_path_env(char *const envp[]) {
    int i = 0;
    while (envp[i]) {
        if (strncmp(envp[i], "PATH=", 5) == 0)
            return strdup(envp[i]);
        i++;
    }
    return NULL;
}

int main(int argc, char *argv[], char *envp[]) {
    char *path_env = get_path_env(envp);
    if (path_env) {
        printf("%s", path_env);
        free(path_env); // Don't forget to free the allocated memory
    } else {
        printf("PATH environment variable not found\n");
    }
    return 0;
}

// int main(int argc, char *argv[], char *envp[]) {
// 	for (int i = 0; envp[i]; i++) {
// 		printf("%s\n", envp[i]);
// 	}
//     return 0;
// }
