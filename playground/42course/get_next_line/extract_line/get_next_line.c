/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/14 14:52:51 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
