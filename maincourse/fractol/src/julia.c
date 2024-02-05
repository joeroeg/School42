/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:22:30 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 18:01:39 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * Renders a single pixel of the Julia set based on the iteration count.
 * Iterates a complex number calculation to determine the color of a pixel.
 *
 * @param data Contain the complex number for calculation and rendering.
 *
 * Iteration process:
 * - 1. Continues until n reaches MAX_ITERATIONS or
 * 		the magnitude of the complex number exceeds 2 (escape condition).
 * - 2. Squares the current complex number (data->z)
 * 		and adds a constant complex number (data->c) to it.
 * - 3. Increments n each cycle through the loop.
 *
 * Coloring:
 * - The color of the pixel is determined by the number of iterations (n).
 */
void	julia_render(t_fractol *data)
{
	int	n;

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

/**
 * Renders the Julia set for a given set of parameters.
 * Iterates over each pixel, converting pixel coordinates to complex plane.
 *
 * @param data Structure containing fractal parameters and image buffer.
 *
 * Loops through pixels:
 * - Outer loop increments y from 0 to data->height.
 * - Inner loop increments x from 0 to data->width.
 * Maps (x, y) to a complex number (data->z):
 * - Real is calculated from x, mapping to [min, max]
 * - Imaginary is calculated from y, mapping to [min, max]
 * Calls julia_render(data) to render the fractal at each pixel position.
 *
 * Iteration over x and y covers the entire viewport.
 */
void	julia(t_fractol *data)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			data->z.real = data->min_real + \
			(data->x / (data->width - 1.0)) * \
				(data->max_real - data->min_real) / data->zoom;
			data->z.imag = data->min_imaginary + \
				(data->y / (data->height - 1.0)) * \
				(data->max_imaginary - data->min_imaginary) / data->zoom;
			julia_render(data);
			data->x++;
		}
		data->y++;
	}
}
