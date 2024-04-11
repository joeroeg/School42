/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:04:32 by gcrepin           #+#    #+#             */
/*   Updated: 2024/04/10 14:52:19 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void load_textures(t_cub *data)
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
