/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:50:17 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/11 15:20:48 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd1(t_pipex_data *data)
{
	int	infile_fd;

	close(data->pipe_fds[0]);
	infile_fd = open(data->argv[1], O_RDONLY);
	if (infile_fd == -1)
	{
		cleanup(data);
		error_message("open infile", 1);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(data->pipe_fds[1], STDOUT_FILENO);
	close(data->pipe_fds[1]);
	ft_execvp(data->cmd1_args[0], data->cmd1_args, data->envp);
	cleanup(data);
	exit(1);
}

void	exec_cmd2(t_pipex_data *data)
{
	int	outfile_fd;

	close(data->pipe_fds[1]);
	outfile_fd = open(data->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		cleanup(data);
		error_message("open outfile", 1);
	}
	dup2(data->pipe_fds[0], STDIN_FILENO);
	close(data->pipe_fds[0]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	ft_execvp(data->cmd2_args[0], data->cmd2_args, data->envp);
	cleanup(data);
	exit(1);
}

char	**parse_command(char *cmd)
{
	char	**argv;
	int		i;
	char	*token;

	if (cmd == NULL || *cmd == '\0' || *cmd == ' ')
	{
		error_message("empty command", 0);
		return (NULL);
	}
	argv = malloc((MAX_ARGS + 1) * sizeof(char *));
	i = 0;
	token = ft_strtok(cmd, " ");
	while (token != NULL && i < MAX_ARGS)
	{
		argv[i++] = ft_strdup(token);
		token = ft_strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}

t_pipex_data	init_pipex_data(int argc, char **argv, char **envp)
{
	t_pipex_data	data;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		error_message("Error: wrong number of arguments", 1);
	}
	data.cmd1_args = parse_command(argv[2]);
	data.cmd2_args = parse_command(argv[3]);
	if (data.cmd1_args == NULL || data.cmd2_args == NULL)
	{
		free_string_array(&data.cmd1_args);
		free_string_array(&data.cmd2_args);
		error_message("parse_command", 1);
	}
	if (pipe(data.pipe_fds) == -1)
		error_message("pipe", 1);
	data.argv = argv;
	data.envp = envp;
	return (data);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	data;
	pid_t			pid1;
	pid_t			pid2;

	data = init_pipex_data(argc, argv, envp);
	if (pipe(data.pipe_fds) == -1)
		error_message("pipe", 1);
	pid1 = fork();
	if (pid1 < 0)
		error_message("fork", 1);
	if (pid1 == 0)
		exec_cmd1(&data);
	pid2 = fork();
	if (pid2 < 0)
		error_message("fork", 1);
	if (pid2 == 0)
		exec_cmd2(&data);
	close(data.pipe_fds[0]);
	close(data.pipe_fds[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_string_array(&data.cmd1_args);
	free_string_array(&data.cmd2_args);
	return (0);
}
