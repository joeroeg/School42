#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		return (NULL); // checked
	}
	ft_strlcpy(fullpath, dir, length);
	ft_strlcat(fullpath, "/", length);
	ft_strlcat(fullpath, file, length);
	if (access(fullpath, X_OK) == 0)
		return (fullpath); // checked
	free(fullpath);
	return (NULL); // checked
}

char	*search_command_in_directories(const char *file, char *path)
{
	char	**directories;
	char	*fullpath;
	int		i;
	size_t	length;

	directories = tokenize_path(path);
	if (!directories)
		return (NULL); // checked
	i = -1;
	while (directories[++i])
	{
		length = strlen(directories[i]) + 1 + strlen(file) + 1;
		fullpath = build_and_check_exec(directories[i], file, length);
		if (fullpath)
			break ; // checked
	}
	// free_string_array(&directories);
	return (fullpath); // checked
}

int	execute_command(char *fullpath, char *const argv[])
{
	if (fullpath)
	{
		execv(fullpath, argv);
		perror("execv");
		free(fullpath);
		return (-1);
	}
	else
	{
		fprintf(stderr, "Command not found\n");
		return (-1);
	}
}

int main() {
    char *command = "ls"; // The command to search for
    char *path = "/bin:/usr/bin:/usr/local/bin"; // Directories to search in

    // Search for the command in the given directories
    char *fullpath = search_command_in_directories(command, path);
    if (fullpath) {
        printf("Command found: %s\n", fullpath);

        // Arguments for the command, NULL terminated
        char *argv[] = {fullpath, NULL};

        // Execute the found command
        int status = execute_command(fullpath, argv);
        free(fullpath); // Free the fullpath after use

        return status;
    } else {
        printf("Command not found.\n");
        return -1;
    }
}
