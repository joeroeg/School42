#include "cub3d.h"
#include "render.h"
#include "player.h"

double delta_time(bool update)
{
	static double current_time = 0;
	static double last_time = 0;
	double delta_time;

	if (update)
	{
		last_time = current_time;
		current_time = mlx_get_time();
		return (0);
	}
	delta_time = current_time - last_time;
	return (delta_time);
}

unsigned int get_pixel_color(mlx_texture_t *image, int x, int y)
{
	unsigned char *pixel;

	pixel = &image->pixels[(y * image->width + x) * 4];
	return ((unsigned int) (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 |
							pixel[3]));
}

void
draw_wall(t_cub *data, int height, int x, t_direction direction, double trail)
{
	int pixel;
	int i;

	pixel = (int) (trail * data->render.textures[direction]->width);
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		if (i < (WINDOW_HEIGHT - height) / 2)
			mlx_put_pixel(data->render.screen, x, i,
						  data->config.ceiling_color_r << 24 |
						  data->config.ceiling_color_g << 16 |
						  data->config.ceiling_color_b << 8 | 0xFF);
		else if (i >= (WINDOW_HEIGHT + height) / 2)
			mlx_put_pixel(data->render.screen, x, i,
						  data->config.floor_color_r << 24 |
						  data->config.floor_color_g << 16 |
						  data->config.floor_color_b << 8 | 0xFF);
		else
			mlx_put_pixel(data->render.screen, x, i,
						  get_pixel_color(data->render.textures[direction],
										  pixel, (int) ((i - (WINDOW_HEIGHT -
															height) / 2) *
														data->render.textures[direction]->height /
														height)));
		i++;
	}
}

void draw_column(t_cub *data, double distance, int x, t_direction direction,
		double trail)
{
	int wall_height;

	wall_height = WINDOW_HEIGHT / distance;
	draw_wall(data, wall_height, x, direction, trail);
}



static void draw_player_2d(t_cub *data)
{
	player_move(data);
	draw_rays(data);
}

void fps_counter(t_cub *data)
{
	static int fps = 0;
	static double last_time = 0;
	double current_time;
	static mlx_image_t *fps_image;
	char	*nbr;
	char *fps_str;

	current_time = mlx_get_time();
	fps = (int) (1 / delta_time(false));
	if ((int) current_time - (int) last_time > 0)
	{
		last_time = current_time;
		mlx_delete_image(data->render.mlx, fps_image);
		nbr = ft_itoa(fps);
		fps_str = ft_strjoin("FPS: ", nbr);
		fps_image = mlx_put_string(data->render.mlx, fps_str, 0, 0);
		free(nbr);
		free(fps_str);
	}
}

void mlx_render(void *ptr)
{
	t_cub *data;

	data = (t_cub *) ptr;
	delta_time(true);
	cub_rotate(data);
	draw_player_2d(data);
	fps_counter(data);
}


