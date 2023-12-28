#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_ARGS 10


char **parse_command(const char *cmd) {
    char **argv = malloc((MAX_ARGS + 1) * sizeof(char *));
    if (argv == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    char *temp = strdup(cmd);
    if (temp == NULL) {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int in_quotes = 0;
    char quote_char = '\0';
    char *arg_start = temp;

for (char *p = temp; *p != '\0'; p++) {
    // printf("Current char: %c\n", *p);
    // Handle entering and exiting quotes
    if ((*p == '\'' || *p == '"') && (!in_quotes || *p == quote_char)) {
        if (in_quotes) {
            in_quotes = 0;
            *p = '\0';  // Null-terminate the argument
            if (i < MAX_ARGS) {
                argv[i] = strdup(arg_start);
                // printf("Argument found: %s\n", argv[i]);  // Print the argument found
                i++;
            }
        } else {
            in_quotes = 1;
            quote_char = *p;
            arg_start = p + 1;  // Start after the quote
        }
    } else if (*p == ' ' && !in_quotes) {
        *p = '\0';  // Null-terminate the argument
        if (arg_start != p) {  // Avoid empty arguments
            if (i < MAX_ARGS) {
                argv[i] = strdup(arg_start);
                // printf("Argument found: %s\n", argv[i]);  // Print the argument found
                i++;
            }
        }
        arg_start = p + 1;
    }
}

    if (in_quotes) {
        fprintf(stderr, "Unmatched quote in command\n");
        for (int j = 0; j < i; j++) free(argv[j]);
        free(argv);
        free(temp);
        return NULL;
    }

	// Handle last argument outside the loop
	if (*arg_start != '\0' && !in_quotes && i < MAX_ARGS) {
    argv[i] = strdup(arg_start);
    // printf("Argument found: %s\n", argv[i]);  // Print the argument found
    i++;
	}

    argv[i] = NULL; // NULL-terminate the array
    free(temp);
    return argv;
}

int ft_execvp2(const char *file, char *const argv[], char *const envp[]) {

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

int ft_execvp(const char *file, char *const argv[], char *const envp[]) {
    char *path_env = NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path_env = envp[i] + 5; // Skip the "PATH=" part
            break;
        }
    }

    if (path_env == NULL) {
        fprintf(stderr, "PATH not found\n");
        return -1;
    }

    char *path = strdup(path_env); // Duplicate the PATH string for strtok
    if (path == NULL) {
        perror("strdup");
        return -1;
    }

    char fullPath[1024];
    char *dir = strtok(path, ":");
    while (dir != NULL) {
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dir, file);
        if (access(fullPath, X_OK) == 0) {
            // Execute the command
            pid_t pid = fork();
            if (pid == 0) {
                execv(fullPath, argv);
                perror("execv");
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                int status;
                waitpid(pid, &status, 0);
                free(path); // Free the duplicated string
                return status;
            } else {
                perror("fork");
                free(path); // Free the duplicated string
                return -1;
            }
        }
        dir = strtok(NULL, ":");
    }

    free(path); // Free the duplicated string
    fprintf(stderr, "%s: command not found\n", file);
    return -1;
}


// int main(int argc, char **argv, char **envp) {
//     char **cmd1_args = parse_command(argv[1]);
//     for (int i = 0; cmd1_args[i] != NULL; i++) {
//         printf("token [%d]: '%s'\n", i, cmd1_args[i]);
//     }
//     ft_execvp(argv[1], cmd1_args, envp);
// }

int main(int argc, char **argv, char **envp) {
    char *cmd1_args[] = {"/bin/ls", "-l", NULL};
    ft_execvp(cmd1_args[0], cmd1_args, envp);
}

