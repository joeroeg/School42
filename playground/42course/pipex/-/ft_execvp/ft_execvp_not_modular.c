#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int ft_execvp(const char *file, char *const argv[], char *const envp[]) {
    const char *path_const = NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path_const = envp[i] + 5;
            break;
        }
    }

    if (path_const == NULL) {
        fprintf(stderr, "PATH not found\n");
        return -1;
    }

    char *path = strdup(path_const);
    if (path == NULL) {
        perror("strdup");
        return -1;
    }

    char *p = strtok(path, ":");
    while (p != NULL) {
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", p, file);

        if (access(fullPath, X_OK) == 0) {
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execv(fullPath, argv);
                perror("execv");
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                // Parent process
                int status;
                waitpid(pid, &status, 0);
                free(path);  // Free the duplicated string
                return status;
            } else {
                // Fork failed
                perror("fork");
                free(path);  // Free the duplicated string
                return -1;
            }
        }
        p = strtok(NULL, ":");
    }

    free(path);  // Free the duplicated string

    fprintf(stderr, "%s: command not found\n", file);
    return -1;
}
