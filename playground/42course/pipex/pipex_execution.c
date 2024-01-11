#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	**tokenize_path(const char *path)
{
	char	**token_array;

	token_array = ft_split(path, ':');
	if (token_array == NULL)
	{
		error_message("ft_split", 0);
		return (NULL);
	}
	return (token_array);
}

char	*build_and_check_exec(const char *dir, const char *file, size_t length)
{
	char	*fullpath;

	fullpath = malloc(length);
	if (!fullpath)
	{
		perror("malloc");
		return (NULL);
	}
	strlcpy(fullpath, dir, length);
	strlcat(fullpath, "/", length);
	strlcat(fullpath, file, length);
	if (access(fullpath, X_OK) == 0)
		return (fullpath);
	free(fullpath);
	return (NULL);
}

char	*search_command_in_directories(const char *file, char *path)
{
	char	**directories;
	char	*fullpath;
	int		i;
	size_t	length;

	directories = tokenize_path(path);
	if (!directories)
		return (NULL);
	i = -1;
	while (directories[++i])
	{
		length = strlen(directories[i]) + 1 + strlen(file) + 1;
		fullpath = build_and_check_exec(directories[i], file, length);
		if (fullpath)
			break ;
	}
	free_string_array(&directories);
	return (fullpath);
}

char	*find_command_path(const char *file, char *const envp[])
{
	char	*path;
	char	*command_path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = strdup(envp[i] + 5);
			break ;
		}
		i++;
	}
	if (!path)
	{
		fprintf(stderr, "PATH not found in envp\n");
		return (NULL);
	}
	command_path = search_command_in_directories(file, path);
	free(path);
	return (command_path);
}

int	execute_command(char *fullpath, char *const argv[], char *const envp[])
{
	if (fullpath)
	{
		execve(fullpath, argv, envp);
		perror("execve");
		free(fullpath);
		return (-1);
	}
	else
	{
		fprintf(stderr, "Command not found\n");
		return (-1);
	}
}

int	ft_execvp(const char *file, char *const argv[], char *const envp[])
{
	char	*command_path;
	int		result;

	command_path = find_command_path(file, envp);
	result = execute_command(command_path, argv, envp);
	if (command_path)
		free(command_path);
	return (result);
}



void test_ft_execvp(const char *command) {
    char *argv[] = { (char *)command, NULL };
    char *envp[] = { getenv("PATH"), NULL };

    printf("Executing command: %s\n", command);
    int result = ft_execvp(command, argv, envp);
    printf("Result: %d\n", result);
}

int main() {
    test_ft_execvp("ls");

    return 0;
}
