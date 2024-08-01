/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:42:55 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/10 20:05:46 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error_message(char *message, int exit_value)
{
	ft_putendl_fd(message, STDERR_FILENO);
	gc_free_all();
	exit(exit_value);
}

int	get_next_line(int fd, char **line)
{
	char	buf[2];
	int		ret;
	char	*temp;

	*line = gc_malloc(1);
	if (!*line)
		exit_error_message("Error: Malloc failed", EXIT_FAILURE);
	**line = '\0';
	while (1)
	{
		ret = (int) read(fd, buf, 1);
		if (ret == -1)
			exit_error_message("Error: Read failed", EXIT_FAILURE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		if (buf[0] == '\n')
			break ;
		temp = ft_strjoin_gc(*line, buf);
		gc_free(*line);
		*line = temp;
	}
	return (ret);
}

char	*trim_space(const char *str)
{
	const char	*start;
	const char	*end;
	char		*trimmed;
	size_t		trimmed_length;

	start = str;
	while (ft_isspace((unsigned char)*start))
		start++;
	if (*start == 0)
	{
		trimmed = gc_malloc(1);
		if (!trimmed)
			exit_error_message(MALLOC_ERROR, EXIT_FAILURE);
		*trimmed = '\0';
		return (trimmed);
	}
	end = str + ft_strlen(str) - 1;
	while (end > start && ft_isspace((unsigned char)*end))
		end--;
	trimmed_length = end - start + 1;
	trimmed = gc_malloc(trimmed_length + 1);
	ft_strncpy(trimmed, start, trimmed_length);
	trimmed[trimmed_length] = '\0';
	return (trimmed);
}

int	prepare_file_descriptor(const char *file_path)
{
	int	fd;

	fd = gc_open(file_path, O_RDONLY, 0);
	if (fd == -1)
		exit_error_message("Error: Invalid file descriptor.", EXIT_FAILURE);
	return (fd);
}
