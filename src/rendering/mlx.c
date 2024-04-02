#include "cub3d.h"

#define ZOOM 3

void mlx_clear(mlx_image_t *pImage);

static void	load_textures(t_cub *data)
{
	data->render.textures[0] = mlx_load_png(data->config.north_texture);
	data->render.textures[1] = mlx_load_png(data->config.south_texture);
	data->render.textures[2] = mlx_load_png(data->config.west_texture);
	data->render.textures[3] = mlx_load_png(data->config.east_texture);
	if (!data->render.textures[0] || !data->render.textures[1] || \
		!data->render.textures[2] || !data->render.textures[3])
		exit_error_message("Error: mlx_load_png() failed.", EXIT_FAILURE);
}

void	mlx_load(t_cub *data)
{
	data->render.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!data->render.mlx)
		exit_error_message("Error: mlx_init() failed.", EXIT_FAILURE);
	data->render.screen = mlx_new_image(data->render.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->render.screen)
		exit_error_message("Error: mlx_new_image() failed.", EXIT_FAILURE);
	load_textures(data);
	mlx_image_to_window(data->render.mlx, data->render.screen, 0, 0);
}

static void	draw_circle(mlx_image_t *pImage, int x, int y, int radius, unsigned int color)
{
	int	i;
	int	j;
	int	x0;
	int	y0;
	
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			x0 = i - x;
			y0 = j - y;
			if (x0 * x0 + y0 * y0 <= radius * radius)
				mlx_put_pixel(pImage, i, j, color);
			j++;
		}
		i++;
	}
}

static	void	draw_player(t_cub *data)
{
	int	x;
	int	y;
	
	x = (data->player.x * (WINDOW_WIDTH / (MAX_MAP_WIDTH / ZOOM))) + (WINDOW_WIDTH / (MAX_MAP_WIDTH / ZOOM)) / 2;
	y = (data->player.y * (WINDOW_HEIGHT / (MAX_MAP_HEIGHT / ZOOM))) + (WINDOW_HEIGHT / (MAX_MAP_HEIGHT / ZOOM)) / 2;
	draw_circle(data->render.screen, x, y, (WINDOW_HEIGHT / (MAX_MAP_HEIGHT / ZOOM)) / 3, 0x0000FFFF);
}

void	mlx_render(t_cub *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	unsigned int	color;
	
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			x = i / (WINDOW_WIDTH / (MAX_MAP_WIDTH / ZOOM));
			y = j / (WINDOW_HEIGHT / (MAX_MAP_HEIGHT / ZOOM));
			if (data->map[y][x] == '1')
				mlx_put_pixel(data->render.screen, i, j, 0x333333FF);
//			else if (data->map[y][x] == 'N')
//				mlx_put_pixel(data->render.screen, i, j, 0x0000FFFF);
			else
				mlx_put_pixel(data->render.screen, i, j, 0x666666FF);
//			printf("i: %d, j: %d, x: %d, y: %d\n", i, j, x, y);
			j++;
		}
		i++;
	}
	draw_player(data);
}


