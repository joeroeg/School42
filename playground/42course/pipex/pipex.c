#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv, char **env)
{
	int	pipefd[2];
	pid_t	pid;
	char	*cmd1[] = {"/bin/ls", "-l", NULL};
	char	*cmd2[] = {"/usr/bin/wc", "-l", NULL};

	if (argc != 5)
	{
		printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(cmd1[0], cmd1, env);
		perror("execve");
		exit(1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(cmd2[0], cmd2, env);
	perror("execve");
	exit(1);
}
