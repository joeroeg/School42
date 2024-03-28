#include "cub3d.h"

/**
 * @brief error_message prints an error message to the standard error output
 * @param message is the message to be printed
 * @param exit_value flag if should exit after printing the message or no
 * @return void
*/
void	exit_error_message(char *message, int exit_value)
{
	ft_putendl_fd(message, STDERR_FILENO);
	if (exit_value == EXIT_FAILURE)
	{
		// gc_free_all();
		exit(EXIT_FAILURE);
	}
	else if (exit_value == EXIT_SUCCESS)
	{
		// gc_free_all();
		exit(EXIT_SUCCESS);
	}
}

int	error_message(char *message, int return_value)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (return_value);
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
		ret = read(fd, buf, 1);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		if (buf[0] == '\n')
			break ;
		temp = ft_strjoin_gc(*line, buf);
		gc_free(*line);
		*line = temp;
	}
	if (ret == -1)
		exit_error_message("Error: Read failed", EXIT_FAILURE);
	return (ret);
}
