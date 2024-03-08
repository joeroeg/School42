/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:53:01 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:42 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * Computes and renders a single pixel of the Burning Ship fractal.
 *
 * @param c Initial complex number based on pixel position.
 * @param data Contains rendering settings and the image buffer for drawing.
 *
 * Iteration loop:
 * - Continues until iter reaches MAX_ITERATIONS.
 * - Calculates the next value of z based on the Burning Ship formula:
 *   1. Takes the absolute value of the current z (z_abs).
 *   2. Computes the next z using z_abs squared plus the initial number c.
 * - Breaks if the magnitude of z squared exceeds 4 (escape condition).
 * - Increments iter each cycle through the loop.
 *
 * After completing iterations or breaking out of the loop:
 * - mlx_put_pixel to draw the pixel with a color based on the iteration count.
 */
void	burning_ship_render(t_complex c, t_fractol *data)
{
	int			iter;
	t_complex	z;
	t_complex	z_abs;

	iter = 0;
	z.real = 0;
	z.imag = 0;
	while (iter < MAX_ITERATIONS)
	{
		z_abs.real = fabs(z.real);
		z_abs.imag = fabs(z.imag);
		z.real = z_abs.real * z_abs.real - z_abs.imag * z_abs.imag + c.real;
		z.imag = 2 * z_abs.real * z_abs.imag + c.imag;
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		iter++;
	}
	mlx_put_pixel(data->image, data->x, data->y, set_color(iter, data));
}

/**
 * Renders the Burning Ship fractal on the given data canvas.
 * Iterates over each pixel, converting pixel coordinates to complex plane.
 * Then calls burning_ship_render() for the actual rendering of each pixel.
 *
 * @param data Structure holding canvas dimensions, zoom, and fractal bounds.
 *
 * Loop through canvas pixels:
 * - y-axis: 0 to data->height
 * - x-axis: 0 to data->width
 * Converts pixel (x, y) to complex number (c) with:
 * - Real part (real): Maps x to fractal's real axis, adjusted by zoom.
 * - Imaginary part (imag): Maps y to fractal's imaginary axis, adjusted by zoom.
 * Calls burning_ship_render(c, data) to compute and plot pixel color.
 *
 * Loops increment x, y to cover entire canvas.
 */
void	burning_ship(t_fractol *data)
{
	double		real;
	double		imaginary;
	t_complex	c;

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
			c.real = real;
			c.imag = imaginary;
			burning_ship_render(c, data);
			data->x++;
		}
		data->y++;
	}
}
