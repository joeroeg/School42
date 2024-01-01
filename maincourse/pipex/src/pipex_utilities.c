/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:13:38 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/31 20:26:24 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	validate_arguments(int argc)
{
	if (argc != 5)
	{
		fprintf(stderr, "Error: wrong number of arguments\n");
		return (1); // checked
	}
	return (0); // checked
}

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	if (*array == NULL)
		return ; // checked
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
		exit(1); // checked
}

char	**tokenize_path(const char *path)
{
	char	**token_array;

	token_array = ft_split(path, ':');
	if (token_array == NULL)
	{
		error_message("ft_split", 0);
		return (NULL); // checked
	}
	return (token_array); // checked
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
