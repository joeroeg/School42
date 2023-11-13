/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/13 16:36:19 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char *get_next_line(int fd) {
    static char *static_buffer = NULL;
    char *buffer;
    char *line = NULL;
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


// char	*get_next_line(int fd)
// {
// 	static char	*static_buffer = NULL;
// 	char		*buffer;
// 	char		*line;
// 	ssize_t		bytes_read;
// 	char		*temp;

// 	buffer = malloc(BUFFER_SIZE + 1);
// 	line = NULL;
// 	if (fd < 0 || !buffer)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	while (1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 		{
// 			free(buffer);
// 			free(static_buffer);
// 			static_buffer = NULL;
// 			return (NULL);
// 		}
// 		if (bytes_read > 0)
// 		{
// 			buffer[bytes_read] = '\0';
// 			temp = ft_strjoin(static_buffer, buffer);
// 			if (!temp)
// 			{
// 				free(buffer);
// 				free(static_buffer);
// 				static_buffer = NULL;
// 				return (NULL);
// 			}
// 			free(static_buffer);
// 			static_buffer = temp;
// 		}
// 		if (ft_strchr(static_buffer, '\n')
// 			|| (bytes_read == 0 && static_buffer && *static_buffer))
// 		{
// 			line = extract_line(&static_buffer);
// 			break ;
// 		}
// 		if (bytes_read == 0)
// 			break ;
// 	}
// 	free(buffer);
// 	if (static_buffer && *static_buffer == '\0')
// 	{
// 		free(static_buffer);
// 		static_buffer = NULL;
// 	}
// 	return (line);
// }
