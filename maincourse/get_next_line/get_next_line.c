/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/13 20:20:24 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ssize_t	read_from_fd(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
	}
	return (bytes_read);
}

char	*update_static_buffer(char **static_buffer, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*static_buffer, buffer);
	if (temp)
	{
		free(*static_buffer);
		*static_buffer = temp;
	}
	return (temp);
}

bool	has_line_break(char *static_buffer, ssize_t bytes_read)
{
	return (
		ft_strchr(static_buffer, '\n') != (NULL)
		|| (bytes_read == 0 && static_buffer && *static_buffer));
}

void	cleanup_buffers(char **buffer, char **static_buffer)
{
	free(*buffer);
	if (*static_buffer && **static_buffer == '\0')
	{
		free(*static_buffer);
		*static_buffer = NULL;
	}
}

char *get_next_line(int fd)
{
    static char *static_buffer = 0;
    char *buffer;
    char *line = 0;
    ssize_t bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (fd < 0 || !buffer) {
        free(buffer);
        return NULL;
    }

    while (1) {
        bytes_read = read_from_fd(fd, buffer);
        if (bytes_read < 0) {
            cleanup_buffers(&buffer, &static_buffer);
			buffer = NULL;
			static_buffer = NULL;
            return NULL;
        }

        if (bytes_read > 0 && !update_static_buffer(&static_buffer, buffer)) {
            cleanup_buffers(&buffer, &static_buffer);
			buffer = NULL;
			static_buffer = NULL;
            return NULL;
        }

        if (has_line_break(static_buffer, bytes_read)) {
            line = extract_line(&static_buffer);
            break;
        }

        if (bytes_read == 0) break;
    }

    cleanup_buffers(&buffer, &static_buffer);
    return line;
}
*/


char	*get_next_line(int fd)
{
	static char	*static_buffer = NULL;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;
	char		*temp;
	buffer = malloc(BUFFER_SIZE + 1);
	line = NULL;
	if (fd < 0 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(static_buffer);
			static_buffer = NULL;
			return (NULL);
		}
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			temp = ft_strjoin(static_buffer, buffer);
			if (!temp)
			{
				free(buffer);
				free(static_buffer);
				static_buffer = NULL;
				return (NULL);
			}
			free(static_buffer);
			static_buffer = temp;
		}
		if (ft_strchr(static_buffer, '\n')
			|| (bytes_read == 0 && static_buffer && *static_buffer))
		{
			line = extract_line(&static_buffer);
			break ;
		}
		if (bytes_read == 0)
			break ;
	}
	free(buffer);
	if (static_buffer && *static_buffer == '\0')
	{
		free(static_buffer);
		static_buffer = NULL;
	}
	return (line);
}


/*
char	*read_and_buffer(int fd, char **static_buffer)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*static_buffer, buffer);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		free(*static_buffer);
		*static_buffer = temp;
	}
	free(buffer);
	return (*static_buffer);
}

char	*get_next_line(int fd)
{
	static char		*static_buffer;
	char			*line;

	static_buffer = NULL;
	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!read_and_buffer(fd, &static_buffer))
	{
		free(static_buffer);
		static_buffer = NULL;
		return (NULL);
	}
	if (ft_strchr(static_buffer, '\n') || (static_buffer && *static_buffer))
		line = extract_line(&static_buffer);
	if (static_buffer && *static_buffer == '\0')
	{
		free(static_buffer);
		static_buffer = NULL;
	}
	return (line);
}
*/
