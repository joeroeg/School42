/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:57:55 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/29 20:04:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
valgrind --leak-check=full ./pipex infile "cat -e" "sort -r" outfile 2>&1 | grep "definitely lost:"
*/

int	validate_arguments(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: [program] [input_file] \
			[command1] [command2] [output_file]\n", 2);
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
		argv[i++] = ft_strdup(token);
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}

pid_t	exec_cmd1(char *infile, char **cmd_args, char **envp, int pipe_fds[2])
{
	pid_t	cmd1;
	int		infile_fd;

	cmd1 = fork();
	if (cmd1 == -1)
		error_message("fork", 1);
	if (cmd1 == 0)
	{
		close(pipe_fds[0]);
		infile_fd = open(infile, O_RDONLY);
		if (infile_fd == -1)
			error_message("open", 1);

		if (dup2(infile_fd, STDIN_FILENO) == -1)
			error_message("dup2", 1);
		close(infile_fd);

		if (dup2(pipe_fds[1], STDOUT_FILENO) == -1)
			error_message("dup2", 1);
		close(pipe_fds[1]);

		if (ft_execvp(cmd_args[0], cmd_args, envp) == -1)
			error_message("execve", 1);
	}
	return (cmd1);
}

pid_t	exec_cmd2(char *outfile, char **cmd_args, char **envp, int pipe_fds[2])
{
	pid_t	cmd2;
	int		outfile_fd;

	cmd2 = fork();
	if (cmd2 == -1)
		error_message("fork", 1);
	if (cmd2 == 0)
	{
		close(pipe_fds[1]);
		if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
			// error_message("dup2", 1); //  <- the problem with this error_message function
		close(pipe_fds[0]);
		outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
			error_message("open", 1);
		if (dup2(outfile_fd, STDOUT_FILENO) == -1)
			error_message("dup2(outfile, stdout)", 1);
		close(outfile_fd);
		if (ft_execvp(cmd_args[0], cmd_args, envp) == -1)
			error_message("execvp", 1);
	}
	return (cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd1_args;
	char	**cmd2_args;
	int		pipe_fds[2];
	pid_t	cmd1;
	pid_t	cmd2;

	if (validate_arguments(argc) != 0)
		return (1);

	cmd1_args = parse_command(argv[2]);
	cmd2_args = parse_command(argv[3]);

	if (pipe(pipe_fds) == -1)
		error_message("pipe", 1);
	cmd1 = exec_cmd1(argv[1], cmd1_args, envp, pipe_fds);
	if (cmd1 < 0)
		return (1);
	cmd2 = exec_cmd2(argv[4], cmd2_args, envp, pipe_fds);
	if (cmd2 < 0)
		return (1);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(cmd1, NULL, 0);
	waitpid(cmd2, NULL, 0);
	free_string_array(cmd1_args);
	free_string_array(cmd2_args);
	return (0);
}
