#include "cub3d.h"

void	validate_map_file(t_cub *data)
{
	const char	*valid_extensions[] = {".cub"};
	int			num_extensions;

	num_extensions = sizeof(valid_extensions) / sizeof(valid_extensions[0]);
	if (check_extension(\
	data->file, valid_extensions, num_extensions) == FAILURE)
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

int	check_extension(const char *filename, \
const char *valid_extensions[], int num_extensions)
{
	const char	*found_extension;
	const char	*dot;
	int			i;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (FAILURE);
	i = 0;
	while (i < num_extensions)
	{
		if (ft_strcmp(dot, valid_extensions[i]) == 0)
			return (SUCCESS);
		i++;
	}
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
	}
	if (result == 0 && line != NULL)
		gc_free(line);
	return (FAILURE);
}
