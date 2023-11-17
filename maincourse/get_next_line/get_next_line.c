/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/16 19:19:11 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffer(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*extract_line(int new_line_position, char **buffer)
{
	char	*output_line;
	char	*temporary_buffer;

	temporary_buffer = NULL;
	if (new_line_position <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		output_line = *buffer;
		*buffer = NULL;
		return (output_line);
	}
	temporary_buffer = ft_substr(*buffer, new_line_position, BUFFER_SIZE);
	output_line = *buffer;
	output_line[new_line_position] = 0;
	*buffer = temporary_buffer;
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
		static_buffer[fd][0] = '\0';
	}
	output_line = read_line(fd, &static_buffer[fd], read_buffer);
	free_buffer(&read_buffer);
	return (output_line);
}
