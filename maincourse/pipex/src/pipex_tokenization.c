/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tokenization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:47:57 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/29 14:57:52 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


int	count_tokens(const char *str, char delimiter)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delimiter)
			count++;
		i++;
	}
	return (count);
}

char	**allocate_token_array(int token_count)
{
	char	**array;

	array = malloc((token_count + 1) * sizeof(char *));
	if (array == NULL)
	{
		error_message("malloc", 1);
		return (NULL);
	}
	return (array);
}

void	free_token_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**tokenize(const char *str, char delimiter, char **token_array)
{
	char	*str_copy;
	char	*token;
	int		index;

	str_copy = ft_strdup(str);
	if (str_copy == NULL)
	{
		error_message("strdup", 1);
		return (NULL);
	}
	token = strtok(str_copy, &delimiter);
	index = 0;
	while (token != NULL)
	{
		token_array[index] = ft_strdup(token);
		if (token_array[index] == NULL)
		{
			free_token_array(token_array, index);
			free(str_copy);
			error_message("strdup", 1);
			return (NULL);
		}
		index++;
		token = strtok(NULL, &delimiter);
	}
	token_array[index] = NULL;
	free(str_copy);
	return (token_array);
}

char	**tokenize_path(const char *path)
{
	int		token_count;
	char	**dirs;

	token_count = count_tokens(path, ':');
	dirs = allocate_token_array(token_count);
	if (dirs == NULL)
		return (NULL);
	return (tokenize(path, ':', dirs));
}
