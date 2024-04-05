#include "cub3d.h"

#define ZOOM 4
#define MOVE_SPEED 0.1

void cub_key_hook(mlx_key_data_t key_data, void *param);
bool cub_check_collision(t_cub *data, double x, double y);

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
	mlx_key_hook(data->render.mlx, cub_key_hook, data);
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

static	void	player_move(t_cub *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x + data->player.vel_x * MOVE_SPEED;
	new_y = data->player.y + data->player.vel_y * MOVE_SPEED;
	if (!cub_check_collision(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!cub_check_collision(data, data->player.x, new_y))
		data->player.y = new_y;
}

static	void	draw_player(t_cub *data)
{
	int	x;
	int	y;

	player_move(data);
	x = (int) (data->player.x * ((double) WINDOW_WIDTH / ((double) MAX_MAP_WIDTH / ZOOM)));
	y = (int) (data->player.y * ((double) WINDOW_HEIGHT / ((double)MAX_MAP_HEIGHT / ZOOM)));
	draw_circle(data->render.screen, x, y, (WINDOW_HEIGHT / (MAX_MAP_HEIGHT / ZOOM)) / 4, 0x0000FFFF);
}

void	fps_counter(t_cub *data)
{
	static int			frames = 0;
	static int			fps = 0;
	static double		last_time = 0;
	double				current_time;
	static mlx_image_t		*fps_image;

	current_time = mlx_get_time();
	frames++;
	fps = (frames / (current_time - last_time));
	if ((int) current_time - (int)last_time > 0)
	{
		last_time = current_time;
		frames = 0;
		mlx_delete_image(data->render.mlx, fps_image);
		fps_image = mlx_put_string(data->render.mlx, ft_itoa(fps), 0, 0);
	}
	if (fps > 100)
	{
		printf("%d:%d FPS: %d\n", (int) current_time, (int) frames, fps);
	}
}

void	mlx_render(void *ptr)
{
	int	i;
	int	j;
	int	x;
	int	y;
	t_cub	*data;

	data = (t_cub *) ptr;
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
	fps_counter(data);
	draw_player(data);
}

bool	cub_check_collision(t_cub *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int) x;
	map_y = (int) y;
	if (map_x < 0 || map_x >= MAX_MAP_WIDTH || map_y < 0 || map_y >= MAX_MAP_HEIGHT)
		return (true);
	if (data->map[map_y][map_x] == '1')
		return (true);
	return (false);
}

void	cub_key_hook(mlx_key_data_t key_data, void *param)
{
	t_cub	*data;

	data = (t_cub *) param;
	if (key_data.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->render.mlx);
		exit(EXIT_SUCCESS);
	}
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_UP)
			data->player.vel_y += -1;
		if (key_data.key == MLX_KEY_DOWN)
			data->player.vel_y += 1;
		if (key_data.key == MLX_KEY_LEFT)
			data->player.vel_x += -1;
		if (key_data.key == MLX_KEY_RIGHT)
			data->player.vel_x += 1;
	}
	if (key_data.action == MLX_RELEASE)
	{
		if (key_data.key == MLX_KEY_UP)
			data->player.vel_y -= -1;
		if (key_data.key == MLX_KEY_DOWN)
			data->player.vel_y -= 1;
		if (key_data.key == MLX_KEY_LEFT)
			data->player.vel_x -= -1;
		if (key_data.key == MLX_KEY_RIGHT)
			data->player.vel_x -= 1;
	}
}
