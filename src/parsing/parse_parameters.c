#include "cub3d.h"

void	parse_map_parameters(t_cub *data)
{
	int	parsed_parameters;

	parsed_parameters = 0;
	data->memory->fd = prepare_file_descriptor(data->file);
	parse_parameters_loop(data, &parsed_parameters);
	validate_all_parameters_set(parsed_parameters);
	validate_all_texture_paths_exist(&data->config);
	// Add here validate_all_color_setup if needed
	// finalize_parameter_parsing(data);
}

void	parse_parameters_loop(t_cub *data, int *parsed_parameters)
{
	char	*line;
	int		total_parameters;
	char	*trimmed_line;

	total_parameters = 6;
	while (get_next_line(data->memory->fd, &line) > 0)
	{
		trimmed_line = trim_space(line);
		parse_parameter(data, trimmed_line, parsed_parameters);
		gc_free(line);
		if (*parsed_parameters == total_parameters)
			break ;
	}
}

void	parse_parameter(t_cub *data, char *trimmed_line, int *parsed_parameters)
{
	if (is_texture_line(trimmed_line))
		parse_texture(data, trimmed_line, parsed_parameters);
	else if (is_color_line(trimmed_line))
	{
		if (ft_strncmp(trimmed_line, "F ", 2) == 0)
			parse_color(data, trimmed_line, 'F', parsed_parameters);
		else if (ft_strncmp(trimmed_line, "C ", 2) == 0)
			parse_color(data, trimmed_line, 'C', parsed_parameters);
	}
}

void	validate_all_parameters_set(int parsed_parameters)
{
	int	total_parameters;

	total_parameters = 6;
	if (parsed_parameters != total_parameters)
		exit_error_message("Error: \
		Not all parameters were specified.", EXIT_FAILURE);
}
