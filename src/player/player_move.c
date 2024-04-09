#include "cub3d.h"
#include "player.h"

static bool	correct_vel(double *vel_x, double *vel_y)
{
	if (*vel_x == 0 && *vel_y == 0)
		return (false);
	if (*vel_x != 0 && *vel_y != 0)
	{
		*vel_x /= sqrt(2);
		*vel_y /= sqrt(2);
	}
	return (true);
}

void player_move(t_cub *data)
{
	double new_x;
	double new_y;
	double corrected_vel_x;
	double corrected_vel_y;

	corrected_vel_x = data->player.vel_x;
	corrected_vel_y = data->player.vel_y;
	if (!correct_vel(&corrected_vel_x, &corrected_vel_y))
		return;
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
