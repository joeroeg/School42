#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*
    Step 1: Finding the PATH Environment Variable
    Step 2: Creating a Mutable Copy of the PATH String
    Step 3: Tokenizing the PATH String and Searching for the Executable
    Step 4: Forking a New Process and Executing the Command
    Step 5: Handling Command Not Found
*/

int ft_execvp(const char *file, char *const argv[], char *const envp[]) {
    /* Step 1: Finding the PATH Environment Variable */
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

    /* Step 2: Creating a Mutable Copy of the PATH String */
    char *path = strdup(path_const);
    if (path == NULL) {
        perror("strdup");
        return -1;
    }

    /* Step 3: Tokenizing the PATH String and Searching for the Executable */
    char *p = strtok(path, ":");
    while (p != NULL) {
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", p, file);

    /* Step 4: Forking a New Process and Executing the Command */
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

    /* Step 5: Handling Command Not Found */
    fprintf(stderr, "%s: command not found\n", file);
    return -1;
}


int main(int argc, char **argv, char **envp) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        return 1;
    }

    ft_execvp(argv[1], &argv[1], envp);
    return 0;
}
