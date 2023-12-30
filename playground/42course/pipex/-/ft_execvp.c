#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

void free_string_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_message(const char *message, int should_exit)
{
	perror(message);
	if (should_exit)
		exit(EXIT_FAILURE);
}

char **tokenize_path(const char *path)
{
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

int ft_execvp(const char *file, char *const argv[], char *const envp[])
{
    pid_t pid;
	int status = -1;
    int i;
    char *path, *fullpath;
    char **directories;
    const char *path_const;

    // Find PATH in the environment variables
    i = 0;
    while (envp[i])
    {
        if (strncmp(envp[i], "PATH=", 5) == 0)
        {
            path_const = envp[i] + 5;
            break;
        }
        i++;
    }
    if (!path_const)
        return -1;

    path = strdup(path_const);
    directories = tokenize_path(path);

    // Iterate over directories in PATH
    for (i = 0; directories[i] != NULL; i++)
    {
        // Build full path
        size_t length = strlen(directories[i]) + 1 + strlen(file) + 1;
        fullpath = malloc(length);
        if (!fullpath)
        {
            perror("malloc");
            continue;
        }
        snprintf(fullpath, length, "%s/%s", directories[i], file);

        // Check if command is executable
        if (access(fullpath, X_OK) == 0)
        {
            // Fork a new process
            pid = fork();
            if (pid == -1)
            {
                perror("fork");
                free(fullpath);
                break;
            }
            else if (pid == 0)
            {
                execv(fullpath, argv);
                perror("execv");
                exit(EXIT_FAILURE);
            }
            else
            {
                waitpid(pid, &status, 0);
                if (WIFEXITED(status))
                    status = WEXITSTATUS(status);
                else
                    status = -1;
                free(fullpath);
                break;
            }
        }
        free(fullpath);
    }

    if (directories[i] == NULL)
        fprintf(stderr, "Command not found: %s\n", file);
    free_string_array(directories);
    free(path);

    return status;
}

int main() {
    char *envp[] = {
        "PATH=/bin:/usr/bin:/usr/local/bin", // Mock PATH
        NULL
    };

    // Test 1: Execute a command that exists in the PATH
    char *argv1[] = { "ls", "-l", NULL };
    printf("Executing 'ls -l':\n");
    if (ft_execvp("ls", argv1, envp) == -1) {
        printf("Failed to execute 'ls'\n");
    }

    // Test 2: Execute a command that doesn't exist
    char *argv2[] = { "nonexistentcommand", NULL };
    printf("\nExecuting 'nonexistentcommand':\n");
    if (ft_execvp("nonexistentcommand", argv2, envp) == -1) {
        printf("Failed to execute 'nonexistentcommand'\n");
    }

    // Test 3: Execute a command with no arguments
    char *argv3[] = { "pwd", NULL };
    printf("\nExecuting 'pwd':\n");
    if (ft_execvp("pwd", argv3, envp) == -1) {
        printf("Failed to execute 'pwd'\n");
    }

    // Add more tests as needed...

    return 0;
}
