/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: device <device@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:52:51 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/16 22:22:47 by device           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	get_next_line(char **line)
{
	char	*buf;
	int		ret;
	char	*temp;

	buf = malloc(sizeof(char) * 2);
	if (!buf)
		error_message("Error: Malloc failed", 1);
	*line = malloc(sizeof(char) * 1);
	if (!*line)
		error_message("Error: Malloc failed", 1);
	**line = '\0';
	while (1)
	{
		ret = read(STDIN_FILENO, buf, 1);
		if (ret == -1)
			break ;
		if (ret <= 0 || buf[0] == '\n')
			break ;
		buf[ret] = '\0';
		temp = ft_strjoin(*line, buf);
		free(*line);
		*line = temp;
	}
	free(buf);
	if (ret == -1)
		error_message("Error: Read failed", 1);
	return (ret);
}

void	here_doc(char *limiter, int write_end)
{
	char	*line;

	while (get_next_line(&line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		write(write_end, line, ft_strlen(line));
		write(write_end, "\n", 1);
		free(line);
	}
	free(line);
}
