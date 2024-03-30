#include "cub3d.h"


void	validate_map_file(t_cub *data)
{
	if (check_extension(data->file, ".cub") == FAILURE)
	{
		close(data->memory->fd);
		exit_error_message("Error: Invalid file extension", EXIT_FAILURE);
	}
	if (check_empty_file(data->memory->fd) == FAILURE)
	{
		close(data->memory->fd);
		exit_error_message("Error: File is empty", EXIT_FAILURE);
	}
	close(data->memory->fd);
}


int	check_extension(char *filename, const char *expected_extension)
{
	const char	*found_extension;

	found_extension = ft_strrchr(filename, '.');
	if (found_extension != NULL && \
		ft_strcmp(found_extension, expected_extension) == 0)
		return (SUCCESS);
	else
		return (FAILURE);
}


int	check_empty_file(int fd)
{
	char	*line;
	int		result;
	char	*current_char;

	result = get_next_line(fd, &line);
	while (result > 0)
	{
		current_char = line;
		while (*current_char != '\0')
		{
			if (ft_isascii(*current_char) && !ft_isspace(*current_char))
			{
				gc_free(line);
				return (SUCCESS);
			}
			current_char++;
		}
		gc_free(line);
		result = get_next_line(fd, &line);
		close(fd);
	}
	if (result == 0 && line != NULL)
		gc_free(line);
	return (FAILURE);
}
