/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/17 15:36:03 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_buffer(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*extract_line(int newline_position, char **static_buffer)
{
	char	*output_line;
	char	*temporary_buffer;

	temporary_buffer = NULL;
	if (newline_position <= 0)
	{
		if (**static_buffer == '\0')
		{
			free(*static_buffer);
			*static_buffer = NULL;
			return (NULL);
		}
		output_line = *static_buffer;
		*static_buffer = NULL;
		return (output_line);
	}
	temporary_buffer = ft_substr(*static_buffer, newline_position, BUFFER_SIZE);
	output_line = *static_buffer;
	output_line[newline_position] = '\0';
	*static_buffer = temporary_buffer;
	return (output_line);
}

void	read_from_fd(int fd, char **static_buffer,
	char *read_buffer, ssize_t *read_length)
{
	char	*temporary_buffer;

	*read_length = read(fd, read_buffer, BUFFER_SIZE);
	if (*read_length > 0)
	{
		read_buffer[*read_length] = '\0';
		temporary_buffer = ft_strjoin(*static_buffer, read_buffer);
		free_buffer(static_buffer);
		*static_buffer = temporary_buffer;
	}
}

char	*read_line(int fd, char **static_buffer, char *read_buffer)
{
	ssize_t	read_length;
	char	*temporary_buffer;
	char	*new_line;

	new_line = ft_strchr(*static_buffer, '\n');
	temporary_buffer = NULL;
	read_length = 0;
	while (new_line == NULL)
	{
		read_from_fd(fd, static_buffer, read_buffer, &read_length);
		if (read_length <= 0)
		{
			if (read_length == -1)
			{
				free_buffer(static_buffer);
				return (NULL);
			}
			return (extract_line(read_length, static_buffer));
		}
		new_line = ft_strchr(*static_buffer, '\n');
	}
	return (extract_line(new_line - *static_buffer + 1, static_buffer));
}

char	*get_next_line(int fd)
{
	static char	*static_buffer[MAX_FD];
	char		*read_buffer;
	char		*output_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	read_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_buffer == NULL)
		return (NULL);
	if (!static_buffer[fd])
	{
		static_buffer[fd] = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (static_buffer[fd] == NULL)
		{
			free_buffer(&read_buffer);
			return (NULL);
		}
		static_buffer[fd][0] = '\0';
	}
	read_buffer[0] = '\0';
	output_line = read_line(fd, &static_buffer[fd], read_buffer);
	free_buffer(&read_buffer);
	return (output_line);
}
