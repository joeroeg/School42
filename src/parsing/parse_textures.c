#include "cub3d.h"

void	parse_texture(t_cub *data, const char *line, int *parsed_parameters)
{
	char		(*texture_ptr)[MAX_PATH_LENGTH];
	const char	*path;
	int			texture_count;

	texture_ptr = NULL;
	if (ft_strncmp(line, "NO ", 3) == 0)
		texture_ptr = &data->config.north_texture;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		texture_ptr = &data->config.south_texture;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		texture_ptr = &data->config.west_texture;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		texture_ptr = &data->config.east_texture;
	if (texture_ptr)
	{
		path = trim_space(line + 3);
		ft_strncpy(*texture_ptr, path, MAX_PATH_LENGTH - 1);
		(*texture_ptr)[MAX_PATH_LENGTH - 1] = '\0';
		if (strchr(*texture_ptr, ' '))
			exit_error_message("Error: Invalid path", EXIT_FAILURE);
		if (check_extension(*texture_ptr, ".png") != SUCCESS)
			exit_error_message("Error: Invalid file extension", EXIT_FAILURE);
	}
	*parsed_parameters += 1;
}

void	validate_all_texture_paths_exist(const t_config *config)
{
	if (config->north_texture[0] == '\0' || \
		config->south_texture[0] == '\0' || \
		config->west_texture[0] == '\0' || \
		config->east_texture[0] == '\0')
		exit_error_message("Error:\
		All required textures are not specified.\n", EXIT_FAILURE);
	if (!can_read_file(config->north_texture) || \
		!can_read_file(config->south_texture) || \
		!can_read_file(config->west_texture) || \
		!can_read_file(config->east_texture))
		exit_error_message("Error: \
		One or more texture files cannot be read.\n", EXIT_FAILURE);
}


