#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

/*
- this is fully functional implementation without l
*/

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
	cmd2_args = parse_command(argv[3]); // parse command 2

	pipe(pipe_fds); // create pipe

	cmd1 = fork(); // create child process
	if (cmd1 == 0)
	{
		close(pipe_fds[0]); // close read end of pipe
		infile_fd = open("infile", O_RDONLY); // open infile
		dup2(infile_fd, STDIN_FILENO); // redirect stdin to infile
		dup2(pipe_fds[1], STDOUT_FILENO); // redirect stdout to write end of pipe
		close(infile_fd); // close infile
		close(pipe_fds[1]); // close write end of pipe
		// execvp(cmd1_args[0], cmd1_args); // execute command 1
		// ft_execvp(cmd1_args[0], cmd1_args, envp); // custom ft_execvp function
		execvp(cmd1_args[0], cmd1_args); // original execvp function
	}

	cmd2 = fork(); // create child process
	if (cmd2 == 0)
	{
		close(pipe_fds[1]); // close write end of pipe
		outfile_fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644); // open outfile
		dup2(pipe_fds[0], STDIN_FILENO); // redirect stdin to read end of pipe
		dup2(outfile_fd, STDOUT_FILENO); // redirect stdout to outfile
		close(pipe_fds[0]); // close read end of pipe
		close(outfile_fd); // close outfile
		execvp(cmd2_args[0], cmd2_args);
	}


	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(cmd1, NULL, 0);
	waitpid(cmd2, NULL, 0);
	free_string_array(cmd1_args);
	free_string_array(cmd2_args);
	return (0);
}
