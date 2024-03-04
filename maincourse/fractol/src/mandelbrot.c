/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:22:56 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:56 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * Renders a pixel based on its membership in the Mandelbrot set.
 *
 * Iterates the formula z = z^2 + c for a complex point c
 * This happens until |z| exceeds 2 or the max iterations are reached.
 * Points within the radius of 2 after max iterations are colored.
 *
 * @param c Complex point being tested.
 * @param z The current value of z in the formula z = z^2 + c.
 * @param max_iterations The maximum number of iterations to perform.
 * @param data Structure containing the image to draw on.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 */
void	mandelbrot_render(t_fractol *data)
{
	int			n;

	data->z = (t_complex){0, 0};
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if (t_complex_abs(data->z) > 2.0)
			break ;
		data->z = add(multiply(data->z, data->z), data->c);
		n++;
	}
	mlx_put_pixel(data->image, data->x, data->y, set_color(n, data));
}

void	mandelbrot(t_fractol *data)
{
	double		real;
	double		imaginary;

	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			real = data->min_real + (data->x / (data->width - 1.0)) * \
			(data->max_real - data->min_real) / data->zoom;
			imaginary = data->min_imaginary + \
			(data->y / (data->height - 1.0)) * \
			(data->max_imaginary - data->min_imaginary) / data->zoom;
			data->c = add((t_complex){real, 0}, (t_complex){0, imaginary});
			mandelbrot_render(data);
			data->x++;
		}
		data->y++;
	}
}
