#include "cub3d.h"

void	set_north_texture(t_cub *data, const char *path, int *parsed_parameters)
{
	strncpy(data->config.north_texture, path, MAX_PATH_LENGTH - 1);
	data->config.north_texture[MAX_PATH_LENGTH - 1] = '\0';
	(*parsed_parameters) += 1;
	data->config.north_set = 1;
}

void	set_south_texture(t_cub *data, const char *path, int *parsed_parameters)
{
	strncpy(data->config.south_texture, path, MAX_PATH_LENGTH - 1);
	data->config.south_texture[MAX_PATH_LENGTH - 1] = '\0';
	(*parsed_parameters) += 1;
	data->config.south_set = 1;
}

void	set_west_texture(t_cub *data, const char *path, int *parsed_parameters)
{
	strncpy(data->config.west_texture, path, MAX_PATH_LENGTH - 1);
	data->config.west_texture[MAX_PATH_LENGTH - 1] = '\0';
	(*parsed_parameters) += 1;
	data->config.west_set = 1;
}

void	set_east_texture(t_cub *data, const char *path, int *parsed_parameters)
{
	strncpy(data->config.east_texture, path, MAX_PATH_LENGTH - 1);
	data->config.east_texture[MAX_PATH_LENGTH - 1] = '\0';
	(*parsed_parameters) += 1;
	data->config.east_set = 1;
}
