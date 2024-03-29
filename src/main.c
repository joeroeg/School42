#include "cub3d.h"


/**
 * @todo add a before map
 * @todo implement parser for map
 * @bug does not parse first line of a config file
*/
void	parse_map_parameters(t_cub *data)
{
	char	*line;
	char	*trimmed_line;

	line = NULL;
	while (get_next_line(data->fd, &line) > 0)
	{
		trimmed_line = trim_space(line);
		printf("trimmed_line: %s\n", trimmed_line);
		if (ft_strncmp(trimmed_line, "NO ", 3) == 0 || \
			ft_strncmp(trimmed_line, "SO ", 3) == 0 || \
			ft_strncmp(trimmed_line, "WE ", 3) == 0 || \
			ft_strncmp(trimmed_line, "EA ", 3) == 0)
			parse_texture(data, trimmed_line);
		else if (strncmp(trimmed_line, "F ", 2) == 0)
			parse_color(data, trimmed_line, 'F');
		else if (strncmp(trimmed_line, "C ", 2) == 0)
			parse_color(data, trimmed_line, 'C');
		gc_free(line);
	}
	if (line)
		gc_free(line);
}

/**
 * @todo validate color range
 * @todo validate texture path
 * @todo validate invalid symbols config
*/
void	parse_texture(t_cub *data, const char *line)
{
	char		(*texture_ptr)[MAX_PATH_LENGTH];
	const char	*path;

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
		strncpy(*texture_ptr, path, MAX_PATH_LENGTH - 1); // replace with ft_strncpy
		(*texture_ptr)[MAX_PATH_LENGTH - 1] = '\0';
	}
}


void	parse_color(t_cub *data, const char *line, char color_type)
{
	char	*token;
	char	*line_cpy;
	int		r;
	int		g;
	int		b;

	line_cpy = ft_strdup_gc(line + 2);
	token = ft_strtok(line_cpy, ",");
	r = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	g = ft_atoi(token);
	token = ft_strtok(NULL, ",");
	b = ft_atoi(token);

	if (color_type == 'F')
	{
		data->config.floor_color_r = r;
		data->config.floor_color_g = g;
		data->config.floor_color_b = b;
	}
	else if (color_type == 'C')
	{
		data->config.ceiling_color_r = r;
		data->config.ceiling_color_g = g;
		data->config.ceiling_color_b = b;
	}
	free(line_cpy);
}


void	parse_map(t_cub *data)
{

}

int	main(int argc, char **argv)
{
	t_cub	data;

	if (argc != 2)
		exit_error_message("Error: Invalid number of arguments.", EXIT_FAILURE);
	ft_memset(&data, 0, sizeof(t_cub));

	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
		exit_error_message("Error: Invalid file descriptor.", EXIT_FAILURE);
	data.filename = argv[1];
	validate_map_file(&data);
	parse_map_parameters(&data);
	print_cub_config(&data);
	// parse_map(&data);
	// render_map();
	// mlx_loop();
	close(data.fd);
	// gc_free_all();
	return (SUCCESS);
}
