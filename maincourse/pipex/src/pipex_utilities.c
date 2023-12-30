/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:13:38 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/30 16:58:22 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
