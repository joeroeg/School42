#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

char	**ft_split(char const *s, char c);

#define MAX_ARGS 10

int	validate_arguments(int argc)
{
	if (argc != 5)
	{
		fprintf(stderr, "Error: wrong number of arguments\n");
		return (1);
	}
	return (0);
}

char	**parse_command(char *cmd)
{
	char	**argv;
	int		i;
	char	*token;

	argv = malloc((MAX_ARGS + 1) * sizeof(char *));
	i = 0;
	token = strtok(cmd, " ");
	while (token != NULL && i < MAX_ARGS)
	{
		argv[i++] = strdup(token);
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}

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
    char **token_array;
    token_array = ft_split(path, ':');
    if (token_array == NULL) {
        error_message("ft_split", 1);
        return NULL;
    }
    return token_array;
}

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

int	main(int argc, char **argv, char **envp)
{
	char	**cmd1_args;
	char	**cmd2_args;
	int		pipe_fds[2];
	pid_t	cmd1;
	pid_t	cmd2;
	int		infile_fd;
	int		outfile_fd;

	if (validate_arguments(argc) != 0)
		return (1);

	cmd1_args = parse_command(argv[2]); // parse command 1
	if (cmd1_args == NULL)
		return (1);
	cmd2_args = parse_command(argv[3]); // parse command 2
	if (cmd2_args == NULL)
		return (1);

	pipe(pipe_fds); // create pipe
	if (pipe(pipe_fds) == -1)
		error_message("pipe", 1);

	cmd1 = fork(); // create child process
	if (cmd1 == 0)
	{
	close(pipe_fds[0]); // close read end of pipe
	infile_fd = open("infile", O_RDONLY); // open infile
	dup2(infile_fd, STDIN_FILENO); // redirect stdin to infile
	close(infile_fd); // close infile
	dup2(pipe_fds[1], STDOUT_FILENO); // redirect stdout to write end of pipe
	close(pipe_fds[1]); // close write end of pipe
	ft_execvp(cmd1_args[0], cmd1_args, envp);
	}

	cmd2 = fork(); // create child process
	if (cmd2 == 0)
	{
		close(pipe_fds[1]); // close write end of pipe
		outfile_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644); // open outfile
		dup2(pipe_fds[0], STDIN_FILENO); // redirect stdin to read end of pipe
		close(pipe_fds[0]); // close read end of pipe
		dup2(outfile_fd, STDOUT_FILENO); // redirect stdout to outfile
		close(outfile_fd); // close outfile
		ft_execvp(cmd2_args[0], cmd2_args, envp);
	}

	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(cmd1, NULL, 0);
	waitpid(cmd2, NULL, 0);
	free_string_array(cmd1_args);
	free_string_array(cmd2_args);
	return (0);
}
