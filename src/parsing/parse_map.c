#include "cub3d.h"

void	check_map_dimensions(int line_number, char *line)
{
	if (line_number >= MAX_MAP_HEIGHT)
		exit_error_message("Error: Map exceeds max height.", EXIT_FAILURE);
	if (ft_strlen(line) > MAX_MAP_WIDTH)
		exit_error_message("Error: Map line exceeds max width.", EXIT_FAILURE);
}

void	check_for_map_spaces(int *found_spaces, char *line)
{
	if (is_line_empty_or_whitespace(line))
		*found_spaces = 1;
	else if (*found_spaces)
		exit_error_message("Error: Map contains empty lines", EXIT_FAILURE);
}

void	process_line(char *line, t_cub *data, \
	int *line_number, int *found_spaces)
{
	if (!is_line_valid(line))
		exit_error_message("Error: Map contains invalid characters.", \
			EXIT_FAILURE);
	if (!is_line_empty_or_whitespace(line))
		data->map_found = 1;
	if (data->map_found)
	{
		check_map_dimensions(*line_number, line);
		check_for_map_spaces(found_spaces, line);
		strcpy(data->map[*line_number], line);
		(*line_number)++;
	}
}



void	parse_map(t_cub *data)
{
	char	*line;
	int		result;
	int		line_number;
	int		found_spaces;

	initialize_map_parsing(data, &line_number, &data->map_found, &found_spaces);
	result = get_next_line(data->memory->fd, &line);
	while (result > 0)
	{
		result = get_next_line(data->memory->fd, &line);
		process_line(line, data, &line_number, &found_spaces);
		free_and_reset_line(&line);
	}
	finalize_map_parsing(data, line_number);
}

