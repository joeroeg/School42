/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:13:38 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/29 20:03:21 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

const	char	*find_path_env(char *const envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*build_full_path(const char *dir, const char *file)
{
	size_t	length;
	char	*fullpath;

	if (dir == NULL || file == NULL)
		return (NULL);
	length = ft_strlen(dir) + 1 + ft_strlen(file) + 1;
	fullpath = malloc(length);
	if (fullpath == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	snprintf(fullpath, length, "%s/%s", dir, file);
	return (fullpath);
}

int	execute_command(const char *fullPath, char *const argv[])
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		execv(fullPath, argv);
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (-1);
		}
	}
}

void	command_not_found(const char *file)
{
	fprintf(stderr, "%s: command not found\n", file);
}

char *get_validated_path(char *const envp[])
{
    const char *path_const;
    char *path;

    path_const = find_path_env(envp);
    if (path_const == NULL)
    {
        fprintf(stderr, "PATH not found\n");
        return NULL;
    }

    path = ft_strdup(path_const);
    if (path == NULL)
    {
        perror("strdup");
    }

    return path;
}

int execute_command_with_path(char *path, const char *file, char *const argv[])
{
    char **directories;
    char *fullpath;
    int status;

    if (path == NULL)
    {
        return -1;
    }

    directories = tokenize_path(path);
    for (int i = 0; directories[i] != NULL; i++)
    {
        fullpath = build_full_path(directories[i], file);
        if (access(fullpath, X_OK) == 0)
        {
            status = execute_command(fullpath, argv);
            // free_string_array(directories); // gives error: pointer being freed was not allocated
            free(fullpath);
            return status;
        }
        free(fullpath);
    }
    free_string_array(directories);
    command_not_found(file);
    return -1;
}


int ft_execvp(const char *file, char *const argv[], char *const envp[])
{
    char *path;
    int status;

    path = get_validated_path(envp);
    status = execute_command_with_path(path, file, argv);
    free(path);
    return status;
}

void free_string_array(char **array)
{
    if (array != NULL)
    {
        for (int i = 0; array[i] != NULL; i++)
        {
            free(array[i]);
        }
        free(array);
    }
}

void	error_message(const char *message, int should_exit)
{
	perror(message);
	if (should_exit)
		exit(EXIT_FAILURE);
}
