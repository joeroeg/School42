/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:36:14 by gcrepin           #+#    #+#             */
/*   Updated: 2024/04/08 21:52:52 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"

void	load_player(t_cub *data)
{
	data->player.x = data->player_y + 0.5;
	data->player.y = data->player_x + 0.5;
	data->player.dir_x = (data->player_direction == 'E')
		- (data->player_direction == 'W');
	data->player.dir_y = (data->player_direction == 'S')
		- (data->player_direction == 'N');
}

void	cub_rotate(t_cub *data)
{
	static bool	init_flag = false;
	static int	previous_mouse_x = 0;
	int			current_mouse_x;
	int			delta;
	double		hold;

	if (!init_flag++)
		mlx_get_mouse_pos(data->render.mlx, &previous_mouse_x, &delta);
	mlx_get_mouse_pos(data->render.mlx, &current_mouse_x, &delta);
	delta = current_mouse_x - previous_mouse_x;
	if (delta)
	{
		hold = data->player.dir_x * cos(delta * ROTATE_SPEED)
			- data->player.dir_y * sin(delta * ROTATE_SPEED);
		data->player.dir_y = data->player.dir_x * sin(delta * ROTATE_SPEED)
			+ data->player.dir_y * cos(delta * ROTATE_SPEED);
		data->player.dir_x = hold;
	}
	if (data->player.dir_x == 0)
		data->player.dir_x = 0.01;
	if (data->player.dir_y == 0)
		data->player.dir_y = 0.01;
	previous_mouse_x = current_mouse_x;
}

bool	cub_check_collision(t_cub *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int) x;
	map_y = (int) y;
	if (map_x < 0 || map_x >= MAX_MAP_WIDTH || map_y < 0
		|| map_y >= MAX_MAP_HEIGHT)
		return (true);
	if (data->map[map_y][map_x] == '1')
		return (true);
	return (false);
}
