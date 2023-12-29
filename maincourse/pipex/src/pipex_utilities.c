/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:13:38 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/29 13:21:30 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

const	char	*find_path_env(char *const envp[])
{
	for (int i = 0; envp[i] != NULL; i++)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			{
				return (envp[i] + 5);  // Skip the "PATH=" part
			}
    }
	return (NULL);  // Return NULL if PATH is not found
}
char	**tokenize_path(const char *path)
{
	int count = 1; // Start with 1 for the first token
    for (int i = 0; path[i] != '\0'; i++)
	{
        if (path[i] == ':')
            count++;
    }
    char** dirs = malloc((count + 1) * sizeof(char*)); // +1 for NULL terminator
    if (dirs == NULL)
		error_message("malloc", 1);
	char* path_dup = ft_strdup(path);
	if (path_dup == NULL)
	{
		free(dirs);
		error_message("strdup", 1);
	}
	char* token = strtok(path_dup, ":");
	int index = 0;
	while (token != NULL)
	{
		dirs[index] = ft_strdup(token);
		if (dirs[index] == NULL)
		{
			for (int j = 0; j < index; j++)
				free(dirs[j]);
			free(dirs);
			free(path_dup);
			error_message("strdup", 1);
		}
		index++;
		token = strtok(NULL, ":");
	}
	dirs[index] = NULL;
	free(path_dup);
	return (dirs);
}

char* build_full_path(const char* dir, const char* file) {
    if (dir == NULL || file == NULL) {
        return NULL;  // Handle null inputs
    }

    // Calculate the required length
    size_t length = ft_strlen(dir) + 1 + ft_strlen(file) + 1;  // +1 for slash and +1 for null-terminator

    // Allocate memory for the full path
    char* fullPath = malloc(length);
    if (fullPath == NULL) {
        perror("malloc");
        return NULL;
    }

    // Construct the full path
    snprintf(fullPath, length, "%s/%s", dir, file);

    return fullPath;
}

int	execute_command(const char *fullPath, char *const argv[])
{
	pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork");
        return -1;
    } else if (pid == 0) {
        // Child process
        execv(fullPath, argv);  // Execute the command
        perror("execv");        // execv only returns if there is an error
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);  // Wait for the child process to finish
        if (WIFEXITED(status)) {   // Check if the child exited normally
            return WEXITSTATUS(status);  // Return the exit status of the child
        } else {
            return -1;  // Child did not exit normally
        }
    }
}

void command_not_found(const char* file) {
    fprintf(stderr, "%s: command not found\n", file);
}

int ft_execvp(const char *file, char *const argv[], char *const envp[]) {
	const char *path_const = find_path_env(envp);
    if (path_const == NULL) {
        fprintf(stderr, "PATH not found\n");
        return -1;
    }
    char *path = ft_strdup(path_const);
    if (path == NULL) {
        perror("strdup");
        return -1;
    }
	char** directories = tokenize_path(path_const);
	for (int i = 0; directories[i] != NULL; i++) {
        char* fullPath = build_full_path(directories[i], file);
        if (access(fullPath, X_OK) == 0) {
            int status = execute_command(fullPath, argv);
            free(fullPath);
            free(directories);
            return status;
        }
        free(fullPath);
    }
    free(directories);

    command_not_found(file);
    return -1;
}

void	error_message(const char *message, int should_exit)
{
	perror(message);
	if (should_exit)
		exit(EXIT_FAILURE);
}
