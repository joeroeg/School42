/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:13:38 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/12 12:56:38 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	cleanup(t_pipex_data *data)
{
	if (data->pipe_fds[0] != -1)
		close(data->pipe_fds[0]);
	if (data->pipe_fds[1] != -1)
		close(data->pipe_fds[1]);
	if (data->cmd1_args != NULL)
		free_string_array(&(data->cmd1_args));
	if (data->cmd2_args != NULL)
		free_string_array(&(data->cmd2_args));
	if (data->argv != NULL)
		free_string_array(&(data->argv));
	if (data->envp != NULL)
		free_string_array(&(data->envp));
	if (data->infile != NULL)
		free(data->infile);
	if (data->outfile != NULL)
		free(data->outfile);
	if (data->limiter != NULL)
		free(data->limiter);
	free(data);
}
