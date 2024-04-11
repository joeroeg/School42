/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:30:17 by gcrepin           #+#    #+#             */
/*   Updated: 2024/04/10 14:44:19 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

static void	mlx_press(mlx_key_data_t key_data, void *param)
{
	t_cub	*data;

	data = (t_cub *) param;
	if (((key_data.key == MLX_KEY_UP)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_W)) \
			|| ((key_data.key == MLX_KEY_W)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_UP)))
		data->player.vel_y += -1;
	if (((key_data.key == MLX_KEY_DOWN)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_S)) \
			|| ((key_data.key == MLX_KEY_S)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_DOWN)))
		data->player.vel_y += 1;
	if (((key_data.key == MLX_KEY_LEFT)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_A)) \
			|| ((key_data.key == MLX_KEY_A)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_LEFT)))
		data->player.vel_x += -1;
	if (((key_data.key == MLX_KEY_RIGHT)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_D)) \
			|| ((key_data.key == MLX_KEY_D)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_RIGHT)))
		data->player.vel_x += 1;
}

static void	mlx_release(mlx_key_data_t key_data, void *param)
{
	t_cub	*data;

	data = (t_cub *) param;
	if (((key_data.key == MLX_KEY_UP)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_W)) || \
			((key_data.key == MLX_KEY_W)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_UP)))
		data->player.vel_y -= -1;
	if (((key_data.key == MLX_KEY_DOWN)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_S)) || \
			((key_data.key == MLX_KEY_S)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_DOWN)))
		data->player.vel_y -= 1;
	if (((key_data.key == MLX_KEY_LEFT)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_A)) || \
			((key_data.key == MLX_KEY_A)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_LEFT)))
		data->player.vel_x -= -1;
	if (((key_data.key == MLX_KEY_RIGHT)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_D)) || \
			((key_data.key == MLX_KEY_D)
			&& !mlx_is_key_down(data->render.mlx, MLX_KEY_RIGHT)))
		data->player.vel_x -= 1;
}

void	cub_key_hook(mlx_key_data_t key_data, void *param)
{
	t_cub	*data;

	data = (t_cub *) param;
	if (key_data.key == MLX_KEY_ESCAPE)
	{
		unload(data);
		exit(EXIT_SUCCESS);
	}
	if (key_data.action == MLX_PRESS)
		mlx_press(key_data, data);
	if (key_data.action == MLX_RELEASE)
		mlx_release(key_data, data);
}
