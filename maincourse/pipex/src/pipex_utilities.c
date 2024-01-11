/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: device <device@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:13:38 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/11 10:10:38 by device           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// t_main_data	init_main_data(int argc, char **argv, char **envp)
// {
// 	t_main_data	main_data;

// 	if (argc != 5)
// 	{
// 		ft_putstr_fd("Error: wrong number of arguments\n", 2);
// 		error_message("usage: ./pipex infile cmd1 cmd2 outfile", 1);
// 	}
// 	main_data.cmd1_args = parse_command(argv[2]);
// 	main_data.cmd2_args = parse_command(argv[3]);
// 	if (main_data.cmd1_args == NULL || main_data.cmd2_args == NULL)
// 	{
// 		free_string_array(&main_data.cmd1_args);
// 		free_string_array(&main_data.cmd2_args);
// 		exit(1);
// 	}
// 	if (pipe(main_data.pipe_fds) == -1)
// 		error_message("pipe", 1);
// 	main_data.cmd_data = init_cmd_data(argv, main_data.pipe_fds, envp);
// 	return (main_data);
// }

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	if (*array == NULL)
		return ;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

void	error_message(const char *message, int should_exit)
{
	perror(message);
	if (should_exit)
		exit(1);
}

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

void	cleanup(int pipe_fds[2], char **cmd1_args, char **cmd2_args)
{
	if (pipe_fds[0] != -1)
		close(pipe_fds[0]);
	if (pipe_fds[1] != -1)
		close(pipe_fds[1]);
	if (cmd1_args != NULL)
		free_string_array(&cmd1_args);
	if (cmd2_args != NULL)
		free_string_array(&cmd2_args);
}
