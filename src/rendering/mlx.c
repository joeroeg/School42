#include "cub3d.h"

#define MOVE_SPEED 0.05
#define ROTATE_SPEED 0.0075
#define VIEW_PLANE_SIZE 0.66
#define VIEW_PLANE_DISTANCE 1

void cub_key_hook(mlx_key_data_t key_data, void *param);

bool cub_check_collision(t_cub *data, double x, double y);

void cub_rotate(t_cub *data);

static void load_textures(t_cub *data)
{
	data->render.textures[0] = mlx_load_png(data->config.north_texture);
	data->render.textures[1] = mlx_load_png(data->config.south_texture);
	data->render.textures[2] = mlx_load_png(data->config.west_texture);
	data->render.textures[3] = mlx_load_png(data->config.east_texture);
	if (!data->render.textures[0] || !data->render.textures[1] || \
        !data->render.textures[2] || !data->render.textures[3])
		exit_error_message("Error: mlx_load_png() failed.", EXIT_FAILURE);
}

void mlx_load(t_cub *data)
{
	data->render.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!data->render.mlx)
		exit_error_message("Error: mlx_init() failed.", EXIT_FAILURE);
	data->render.screen = mlx_new_image(data->render.mlx, WINDOW_WIDTH,
										WINDOW_HEIGHT);
	if (!data->render.screen)
		exit_error_message("Error: mlx_new_image() failed.", EXIT_FAILURE);
	load_textures(data);
	mlx_image_to_window(data->render.mlx, data->render.screen, 0, 0);
	mlx_key_hook(data->render.mlx, cub_key_hook, data);
	mlx_set_cursor_mode(data->render.mlx, MLX_MOUSE_DISABLED);
}

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

static void player_move(t_cub *data)
{
	double new_x;
	double new_y;
	double corrected_vel_x;
	double corrected_vel_y;

	if (data->player.vel_x == 0 && data->player.vel_y == 0)
		return;
	if (data->player.vel_x != 0 && data->player.vel_y != 0)
	{
		corrected_vel_x = data->player.vel_x / sqrt(2);
		corrected_vel_y = data->player.vel_y / sqrt(2);
	} else
	{
		corrected_vel_x = data->player.vel_x;
		corrected_vel_y = data->player.vel_y;
	}
	if (mlx_is_key_down(data->render.mlx, MLX_KEY_LEFT_SHIFT))
	{
		corrected_vel_x *= 2;
		corrected_vel_y *= 2;
	}
	corrected_vel_x *= delta_time(false) * 60;
	corrected_vel_y *= delta_time(false) * 60;
	new_y = data->player.y - corrected_vel_y * MOVE_SPEED * data->player.dir_y +
			corrected_vel_x * MOVE_SPEED * data->player.dir_x;
	new_x = data->player.x - corrected_vel_y * MOVE_SPEED * data->player.dir_x -
			corrected_vel_x * MOVE_SPEED * data->player.dir_y;
	if (!cub_check_collision(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!cub_check_collision(data, data->player.x, new_y))
		data->player.y = new_y;
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

static void draw_rays(t_cub *data)
{
	int i;
	double delta_x;
	double delta_y;
	double slope;
	double ray_x;
	double ray_y;
	int dir_x;
	int dir_y;
	int next_x;
	int next_y;
	double distance_x;
	double distance_y;
	double fin_x;
	double fin_y;
	const int nb_rays = WINDOW_WIDTH;

	i = (int) (-floor((double) nb_rays / 2));
	while (i < (int) ceil((double) nb_rays / 2))
	{
		ray_x = data->player.x -
				(data->player.dir_y * ((double) VIEW_PLANE_SIZE * 2 / nb_rays) *
				 i) + data->player.dir_x * VIEW_PLANE_DISTANCE;
		ray_y = data->player.y +
				(data->player.dir_x * ((double) VIEW_PLANE_SIZE * 2 / nb_rays) *
				 i) + data->player.dir_y * VIEW_PLANE_DISTANCE;
		delta_x = ray_x - data->player.x;
		delta_y = ray_y - data->player.y;
		slope = delta_y / delta_x;
		dir_x = (delta_x > 0) - (delta_x < 0);
		dir_y = (delta_y > 0) - (delta_y < 0);
		next_x = (int) data->player.x + (dir_x > 0);
		ray_x = (double) next_x;
		ray_y = data->player.y + (ray_x - data->player.x) * slope;
		next_y = (int) ray_y;
		while (next_x >= 0 && next_x < MAX_MAP_WIDTH && next_y >= 0 &&
			   next_y < MAX_MAP_HEIGHT)
		{
			if (data->map[next_y][next_x - (dir_x < 0)] == '1')
				break;
			ray_x += dir_x;
			ray_y += dir_x * slope;
			next_x = (int) ray_x;
			next_y = (int) ray_y;
		}
		distance_x = sqrt(pow(ray_x - data->player.x, 2) +
						  pow(ray_y - data->player.y, 2));
		fin_x = ray_x;
		fin_y = ray_y;
		next_y = (int) data->player.y + (dir_y > 0);
		ray_y = (double) next_y;
		ray_x = data->player.x + (ray_y - data->player.y) / slope;
		next_x = (int) ray_x;
		while (next_x >= 0 && next_x < MAX_MAP_WIDTH && next_y >= 0 &&
			   next_y < MAX_MAP_HEIGHT)
		{
			if (data->map[next_y - (dir_y < 0)][next_x] == '1')
				break;
			ray_x += dir_y / slope;
			ray_y += dir_y;
			next_x = (int) ray_x;
			next_y = (int) ray_y;
		}
		distance_y = sqrt(pow(ray_x - data->player.x, 2) +
						  pow(ray_y - data->player.y, 2));
		double temp_y_x =
				((ray_y - (ray_x * data->player.dir_y / data->player.dir_x)) -
				 (data->player.y +
				  (data->player.x * data->player.dir_x / data->player.dir_y))) /
				((-data->player.dir_x / data->player.dir_y) -
				 (data->player.dir_y / data->player.dir_x));
		double temp_y_y =
				temp_y_x * (-data->player.dir_x / data->player.dir_y) +
				(data->player.y +
				 (data->player.x * data->player.dir_x / data->player.dir_y));
		double temp_x_x =
				((fin_y - (fin_x * data->player.dir_y / data->player.dir_x)) -
				 (data->player.y +
				  (data->player.x * data->player.dir_x / data->player.dir_y))) /
				((-data->player.dir_x / data->player.dir_y) -
				 (data->player.dir_y / data->player.dir_x));
		double temp_x_y =
				temp_x_x * (-data->player.dir_x / data->player.dir_y) +
				(data->player.y +
				 (data->player.x * data->player.dir_x / data->player.dir_y));
		double temp_y = sqrt(
				pow(temp_y_x - ray_x, 2) + pow(temp_y_y - ray_y, 2));
		double temp_x = sqrt(
				pow(temp_x_x - fin_x, 2) + pow(temp_x_y - fin_y, 2));
		if (distance_x < distance_y)
			draw_column(data, temp_x, i + WINDOW_WIDTH / 2,
						dir_x < 0 ? WEST : EAST, fin_y - (int) fin_y);
		else
			draw_column(data, temp_y, i + WINDOW_WIDTH / 2,
						dir_y < 0 ? NORTH : SOUTH, ray_x - (int) ray_x);
		i++;
	}
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
	static mlx_image_t *fps_image2;
	static int skipped_frames = 0;
	char *fps_str;

	current_time = mlx_get_time();
	fps = (int) (1 / delta_time(false));
	if ((int) current_time - (int) last_time > 0)
	{
		last_time = current_time;
		mlx_delete_image(data->render.mlx, fps_image);
		fps_str = ft_strjoin("FPS: ", ft_itoa(fps));
		fps_image = mlx_put_string(data->render.mlx, fps_str, 0, 0);
		free(fps_str);
	}
	if (fps > 100)
	{
		skipped_frames++;
		last_time = current_time;
		fps_str = ft_strjoin(ft_itoa(skipped_frames),
							 " fast frames | last high FPS: ");
		fps_str = ft_strjoin(fps_str, ft_itoa(fps));
		mlx_delete_image(data->render.mlx, fps_image2);
		fps_image2 = mlx_put_string(data->render.mlx, fps_str, 0, 20);
		free(fps_str);
		fps_str = ft_strjoin("FPS: ", ft_itoa(fps));
		mlx_delete_image(data->render.mlx, fps_image);
		fps_image = mlx_put_string(data->render.mlx, fps_str, 0, 0);
		free(fps_str);
		printf("%f FPS: %d\n", current_time, fps);
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

bool cub_check_collision(t_cub *data, double x, double y)
{
	int map_x;
	int map_y;

	map_x = (int) x;
	map_y = (int) y;
	if (map_x < 0 || map_x >= MAX_MAP_WIDTH || map_y < 0 ||
		map_y >= MAX_MAP_HEIGHT)
		return (true);
	if (data->map[map_y][map_x] == '1')
		return (true);
	return (false);
}

void cub_key_hook(mlx_key_data_t key_data, void *param)
{
	t_cub *data;

	data = (t_cub *) param;
	if (key_data.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->render.mlx);
		exit(EXIT_SUCCESS);
	}
	if (key_data.action == MLX_PRESS)
	{
		if (((key_data.key == MLX_KEY_UP) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_W)) || \
            ((key_data.key == MLX_KEY_W) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_UP)))
			data->player.vel_y += -1;
		if (((key_data.key == MLX_KEY_DOWN) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_S)) || \
            ((key_data.key == MLX_KEY_S) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_DOWN)))
			data->player.vel_y += 1;
		if (((key_data.key == MLX_KEY_LEFT) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_A)) || \
            ((key_data.key == MLX_KEY_A) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_LEFT)))
			data->player.vel_x += -1;
		if (((key_data.key == MLX_KEY_RIGHT) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_D)) || \
            ((key_data.key == MLX_KEY_D) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_RIGHT)))
			data->player.vel_x += 1;
	}
	if (key_data.action == MLX_RELEASE)
	{
		if (((key_data.key == MLX_KEY_UP) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_W)) || \
            ((key_data.key == MLX_KEY_W) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_UP)))
			data->player.vel_y -= -1;
		if (((key_data.key == MLX_KEY_DOWN) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_S)) || \
            ((key_data.key == MLX_KEY_S) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_DOWN)))
			data->player.vel_y -= 1;
		if (((key_data.key == MLX_KEY_LEFT) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_A)) || \
            ((key_data.key == MLX_KEY_A) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_LEFT)))
			data->player.vel_x -= -1;
		if (((key_data.key == MLX_KEY_RIGHT) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_D)) || \
            ((key_data.key == MLX_KEY_D) &&
			 !mlx_is_key_down(data->render.mlx, MLX_KEY_RIGHT)))
			data->player.vel_x -= 1;
	}
}

void cub_rotate(t_cub *data)
{
	static bool init_flag = false;
	static int previous_mouse_x = 0;
	int current_mouse_x;
	int delta;
	double hold;

	if (!init_flag)
	{
		mlx_get_mouse_pos(data->render.mlx, &previous_mouse_x, &delta);
		init_flag = true;
	}
	mlx_get_mouse_pos(data->render.mlx, &current_mouse_x, &delta);
	delta = current_mouse_x - previous_mouse_x;
	if (delta != 0)
	{
		hold = data->player.dir_x * cos(delta * ROTATE_SPEED) -
			   data->player.dir_y * sin(delta * ROTATE_SPEED);
		data->player.dir_y = data->player.dir_x * sin(delta * ROTATE_SPEED) +
							 data->player.dir_y * cos(delta * ROTATE_SPEED);
		data->player.dir_x = hold;
	}
	if (data->player.dir_x == 0)
		data->player.dir_x = 0.01;
	if (data->player.dir_y == 0)
		data->player.dir_y = 0.01;
	previous_mouse_x = current_mouse_x;
}
