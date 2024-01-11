/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:50:17 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/10 20:53:55 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd1(t_main_data *main_data)
{
	int	infile_fd;

	close(main_data->cmd_data.pipe_fds[0]);
	infile_fd = open(main_data->cmd1_args[1], O_RDONLY);
	if (infile_fd == -1)
	{
		cleanup(main_data->cmd_data.pipe_fds, \
			main_data->cmd1_args, main_data->cmd2_args);
		error_message("open infile", 1);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(main_data->cmd_data.pipe_fds[1], STDOUT_FILENO);
	close(main_data->cmd_data.pipe_fds[1]);
	ft_execvp(main_data->cmd1_args[0], \
		main_data->cmd1_args, main_data->cmd_data.envp);
	cleanup(main_data->cmd_data.pipe_fds, \
		main_data->cmd1_args, main_data->cmd2_args);
	exit(1);
}

void	exec_cmd2(t_main_data *main_data)
{
	int	outfile_fd;

	close(main_data->cmd_data.pipe_fds[1]);
	outfile_fd = open(main_data->cmd2_args[1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		cleanup(main_data->cmd_data.pipe_fds, \
			main_data->cmd1_args, main_data->cmd2_args);
		error_message("open outfile", 1);
	}
	dup2(main_data->cmd_data.pipe_fds[0], STDIN_FILENO);
	close(main_data->cmd_data.pipe_fds[0]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	ft_execvp(main_data->cmd2_args[0], \
		main_data->cmd2_args, main_data->cmd_data.envp);
	cleanup(main_data->cmd_data.pipe_fds, \
		main_data->cmd1_args, main_data->cmd2_args);
	exit(1);
}

int	fork_and_exec_cmd(t_main_data *main_data, void (*exec_cmd)(t_main_data *))
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		error_message("fork", 0);
		cleanup(main_data->cmd_data.pipe_fds, \
			main_data->cmd1_args, main_data->cmd2_args);
		return (1);
	}
	if (pid == 0)
	{
		exec_cmd(main_data);
		cleanup(main_data->cmd_data.pipe_fds, \
			main_data->cmd1_args, main_data->cmd2_args);
		exit(1);
	}
	else
	{
		free_string_array(&main_data->cmd_data.cmd_args);
		return (0);
	}
	return (0);
}

char	**parse_command(char *cmd)
{
	char	**argv;
	int		i;
	char	*token;

	if (cmd == NULL || *cmd == '\0')
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

int	main(int argc, char **argv, char **envp)
{
	t_main_data	main_data;

	main_data = init_main_data(argc, argv, envp);
	if (fork_and_exec_cmd(&main_data, exec_cmd1) != 0)
		return (1);
	main_data.cmd_data.cmd_args = main_data.cmd2_args;
	if (fork_and_exec_cmd(&main_data, exec_cmd2) != 0)
		return (1);
	waitpid(-1, NULL, 0);
	return (0);
}
