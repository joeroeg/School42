/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:51:30 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 21:07:03 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	render(t_fractol *frctl)
{
	if (frctl->fractal_type == 1)
		mandelbrot(frctl);
	else if (frctl->fractal_type == 2)
		julia(frctl, frctl->real, frctl->imaginary);
	else if (frctl->fractal_type == 3)
		burning_ship(frctl);
	else if (frctl->fractal_type == 4)
		newton_fractal(frctl);
}

void	color_shift(keys_t key, t_fractol *frctl)
{
	if (key == MLX_KEY_B)
		frctl->frctl_color = 1;
	if (key == MLX_KEY_R)
		frctl->frctl_color = 2;
	if (key == MLX_KEY_G)
		frctl->frctl_color = 3;
	render(frctl);
}

void	mouse_scroll_wheel(double xdelta, double ydelta, void *param)
{
	t_fractol	*frctl;

	frctl = (t_fractol *)param;
	xdelta += 0;
	if (ydelta < 0)
		frctl->zoom *= 1.1;
	else if (ydelta > 0 && frctl->zoom > 0)
		frctl->zoom *= 0.9;
	if (frctl->fractal_type == 1)
		mandelbrot(frctl);
	render(frctl);
}

void	move(keys_t key, t_fractol *frctl)
{
	if (key == MLX_KEY_UP)
	{
		frctl->min_imaginary -= 0.25 / frctl->zoom;
		frctl->max_imaginary -= 0.25 / frctl->zoom;
	}
	if (key == MLX_KEY_DOWN)
	{
		frctl->min_imaginary += 0.25 / frctl->zoom;
		frctl->max_imaginary += 0.25 / frctl->zoom;
	}
	if (key == MLX_KEY_LEFT)
	{
		frctl->min_real -= 0.25 / frctl->zoom;
		frctl->max_real -= 0.25 / frctl->zoom;
	}
	if (key == MLX_KEY_RIGHT)
	{
		frctl->min_real += 0.25 / frctl->zoom;
		frctl->max_real += 0.25 / frctl->zoom;
	}
	render(frctl);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frctl;

	frctl = (t_fractol *)param;
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_ESCAPE))
	{
		cleanup(frctl);
		exit(0);
	}
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_LEFT))
		move(keydata.key, frctl);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_R)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_G)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_B))
		color_shift(keydata.key, frctl);
}
