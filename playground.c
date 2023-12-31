#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = strlen(s1);
	len2 = strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (new_str == NULL)
		return (NULL);
	strlcpy (new_str, s1, len1 + 1);
	strlcat (new_str, s2, len1 + len2 + 1);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

void	free_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_split(char **arr, int n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*allocate_word(char *start, char *end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	while (start + i < end)
	{
		word[i] = start[i];
		i++;
	}
	word[end - start] = '\0';
	return (word);
}

static void	fill_array(char **arr, char const *s, char c)
{
	char	*start;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			arr[i] = allocate_word(start, (char *)s);
			if (!arr[i])
			{
				free_split(arr, i);
				return ;
			}
			i++;
		}
	}
	arr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fill_array(arr, s, c);
	return (arr);
}

char	**tokenize_path(const char *path)
{
	char	**token_array;

	token_array = ft_split(path, ':');
	if (token_array == NULL)
	{
		// error_message("ft_split", 0);
		return (NULL);
	}
	return (token_array);
}

char	*get_path_env(char *const envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return (strdup(envp[i] + 5));
		i++;
	}
	return (NULL);
}

char	*search_command_in_directories(const char *file, char *path)
{
	char	*fullpath;
	char	**directories;
	int		i;
	size_t	length;

	directories = tokenize_path(path);
	if (!directories)
		return (NULL);
	i = 0;
	while (directories[i] != NULL)
	{
		length = strlen(directories[i]) + 1 + strlen(file) + 1;
		fullpath = malloc(length);
		if (!fullpath)
		{
			perror("malloc");
			continue ;
		}
		ft_snprintf(fullpath, length, "%s/%s", directories[i], file);
		printf("Trying %s\n", fullpath);
		if (access(fullpath, X_OK) == 0)
			break ;
		free(fullpath);
		fullpath = NULL;
		i++;
	}
	free_string_array(directories);
	return (fullpath);
}

char	*find_command_path(const char *file, char *const envp[])
{
	char	*path;
	char	*command_path;

	path = get_path_env(envp);
	if (!path)
	{
		fprintf(stderr, "PATH variable not found\n");
		return (NULL);
	}
	command_path = search_command_in_directories(file, path);
	free(path);
	return (command_path);
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

int	ft_execvp(const char *file, char *const argv[], char *const envp[])
{
	char	*command_path;
	int		result;

	command_path = find_command_path(file, envp);
	result = execute_command(command_path, argv);
	if (command_path)
		free(command_path);
	return (result);
}

int main(int argc, char *argv[], char *envp[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arguments...]\n", argv[0]);
        return 1;
    }

    // The first argument after the program name is the command to execute.
    // The rest of the arguments are passed to the command.
    if (ft_execvp(argv[1], &argv[1], envp) == -1) {
        fprintf(stderr, "Error executing command: %s\n", argv[1]);
        return 1;
    }

    // Normally, if execvp succeeds, the program shouldn't reach this point.
    return 0;
}
