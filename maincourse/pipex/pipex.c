#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

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
	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

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
		execvp(cmd1_args[0], cmd1_args); // execute command 1
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
	free(cmd1_args);
	free(cmd2_args);
	return (0);
}
