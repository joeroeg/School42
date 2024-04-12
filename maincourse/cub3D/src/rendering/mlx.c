/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:11:31 by gcrepin           #+#    #+#             */
/*   Updated: 2024/04/10 16:03:34 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "player.h"

void	draw_wall(t_cub *data, int height, t_direction direction,
		double trail)
{
	int	pixel;
	int	i;
	int	x;

	pixel = (int)(trail * data->render.textures[direction]->width);
	i = 0;
	x = data->render.i + WINDOW_WIDTH / 2;
	while (i < WINDOW_HEIGHT)
	{
		if (i < (WINDOW_HEIGHT - height) / 2)
			mlx_put_pixel(data->render.screen, x, i,
				ceiling_color(data));
		else if (i >= (WINDOW_HEIGHT + height) / 2)
			mlx_put_pixel(data->render.screen, x, i,
				floor_color(data));
		else
			mlx_put_pixel(data->render.screen, x, i,
				get_pixel_color(data->render.textures[direction],
					pixel, (int)((i - (WINDOW_HEIGHT - height) / 2)
						* data->render.textures[direction]->height / height)));
		i++;
	}
}

void	draw_column(t_cub *data, double distance, t_direction direction,
		double trail)
{
	int	wall_height;

	wall_height = WINDOW_HEIGHT / distance;
	draw_wall(data, wall_height, direction, trail);
}

char	*fps_string(int fps)
{
	char	*nbr;
	char	*fps_str;

	nbr = ft_itoa(fps);
	fps_str = ft_strjoin("FPS: ", nbr);
	free(nbr);
	return (fps_str);
}

void	fps_counter(t_cub *data)
{
	static int			fps = 0;
	static double		last_time = 0;
	double				current_time;
	static mlx_image_t	*fps_image;
	char				*fps_str;

	current_time = mlx_get_time();
	fps = (int)(1 / delta_time(false));
	if ((int) current_time - (int) last_time > 0)
	{
		last_time = current_time;
		mlx_delete_image(data->render.mlx, fps_image);
		fps_str = fps_string(fps);
		fps_image = mlx_put_string(data->render.mlx, fps_str, 0, 0);
		free(fps_str);
	}
}

void	mlx_render(void *ptr)
{
	t_cub	*data;

	data = (t_cub *) ptr;
	delta_time(true);
	cub_rotate(data);
	player_move(data);
	draw_rays(data);
	fps_counter(data);
}
