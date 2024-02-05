/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:51:30 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:50 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	redraw(t_fractol *data)
{
	if (data->fractal_type == 1)
		mandelbrot(data);
	else if (data->fractal_type == 2)
		julia(data);
	else if (data->fractal_type == 3)
		burning_ship(data);
	else if (data->fractal_type == 4)
		newton_fractal(data);
}

void	color_shift(keys_t key, t_fractol *data)
{
	int	total_colors;

	total_colors = 3;
	if (key == MLX_KEY_C)
		data->data_color = (data->data_color % total_colors) + 1;
	redraw(data);
}

void	mouse_scroll_wheel(double xdelta, double ydelta, void *param)
{
	t_fractol	*data;

	data = (t_fractol *)param;
	xdelta += 0;
	if (ydelta < 0)
		data->zoom *= 1.1;
	else if (ydelta > 0 && data->zoom > 0)
		data->zoom *= 0.9;
	if (data->fractal_type == 1)
		mandelbrot(data);
	redraw(data);
}

void	move(keys_t key, t_fractol *data)
{
	if (key == MLX_KEY_UP)
	{
		data->min_imaginary -= 0.25 / data->zoom;
		data->max_imaginary -= 0.25 / data->zoom;
	}
	if (key == MLX_KEY_DOWN)
	{
		data->min_imaginary += 0.25 / data->zoom;
		data->max_imaginary += 0.25 / data->zoom;
	}
	if (key == MLX_KEY_LEFT)
	{
		data->min_real -= 0.25 / data->zoom;
		data->max_real -= 0.25 / data->zoom;
	}
	if (key == MLX_KEY_RIGHT)
	{
		data->min_real += 0.25 / data->zoom;
		data->max_real += 0.25 / data->zoom;
	}
	redraw(data);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*data;

	data = (t_fractol *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		cleanup(data);
		exit(0);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(data->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move(keydata.key, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_C))
		color_shift(keydata.key, data);
}
