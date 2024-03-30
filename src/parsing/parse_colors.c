#include "cub3d.h"

/**
 * @todo validate color range
 * @todo validate invalid symbols config
 * @todo validate invalid color config
 * @bug if no space between cardinals and path it will not be parsed (e.g. "NO./path")
 * @bug if no space between color type and color it will not be parsed (e.g. "F255,255,255")
*/
void	parse_color(t_cub *data, const char *line, char color_type, int *parsed_parameters)
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
	*parsed_parameters += 1;
	gc_free(line_cpy);
}
