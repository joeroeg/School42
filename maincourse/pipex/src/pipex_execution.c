/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:56:44 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/30 16:58:39 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int ft_execvp(const char *file, char *const argv[], char *const envp[])
{
    int i;
    char *path, *fullpath;
    char **directories;
    const char *path_const = NULL;

    // Find PATH in the environment variables
    i = 0;
    while (envp[i]) {
        if (strncmp(envp[i], "PATH=", 5) == 0) {
            path_const = envp[i] + 5;
            break;
        }
        i++;
    }
    if (!path_const)
        return -1;

    path = strdup(path_const);
    if (!path) {
        perror("strdup");
        return -1;
    }

    directories = tokenize_path(path);
    if (!directories) {
        free(path);
        return -1;
    }

    // Iterate over directories in PATH
    for (i = 0; directories[i] != NULL; i++) {
        // Build full path
        size_t length = strlen(directories[i]) + 1 + strlen(file) + 1;
        fullpath = malloc(length);
        if (!fullpath) {
            perror("malloc");
            continue;
        }
        snprintf(fullpath, length, "%s/%s", directories[i], file);

        // Check if command is executable
        if (access(fullpath, X_OK) == 0) {
            execv(fullpath, argv);
            // If execv returns, it means an error occurred
            perror("execv");
        }
        free(fullpath);
    }

    fprintf(stderr, "Command not found: %s\n", file);
    free_string_array(directories); // Assuming this function frees the array of strings
    free(path);
    return -1; // Return -1 if the command is not found or execv fails
}
