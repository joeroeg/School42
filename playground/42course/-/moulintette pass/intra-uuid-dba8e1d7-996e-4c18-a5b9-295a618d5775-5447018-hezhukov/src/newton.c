/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:23:02 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:57 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * Calculates the value of the function f(z) for a given t_complex number z.
 * This function is part of the Newton fractal rendering process.
 * We are interested in finding the roots of t_complex functions.
 * The specific function f(z) used in this context is defined as: f(z) = z^3 - 1
 * @param z The t_complex number input for which f(z) is to be calculated.
 * @return The value of f(z) as a t_complex number.
 */
t_complex	f(t_complex z)
{
	return (add(multiply(multiply(z, z), z), (t_complex){-1, 0}));
}

/**
 * Calculates the derivative of the function f(z),
 * The derivative is essential in the Newton-Raphson method for finding roots.
 * It is used to perform iterations towards a root.
 * For the function f(z) = z^3 - 1, its derivative f'(z) is: * f'(z) = 3z^2
 * @param z The t_complex number input for which f'(z) is to be calculated.
 * @return The derivative of f(z) at the point z, as a t_complex number.
 */
t_complex	f_prime(t_complex z)
{
	return ((multiply((t_complex){3, 0}, multiply(z, z))));
}

/**
 * @brief Renders a pixel based on the convergence of the Newton-Raphson method.
 * Newton-Raphson formula z = z - f(z) / f'(z) for a complex point z.
 * It stops when the change in z is less than EPSILON (convergence threshold).
 * Or if f'(z) is zero, which would result in division by zero,
 * Or if the maximum number of * iterations (MAX_ITERATIONS) is reached.
 * The goal is to determine how quickly points converge to a root of the equation
 * The pixel color representing the speed of convergence.
 *
 * @param data Structure containing: image, point z, and the pixel coordinates.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 * @param iter The number of iterations it took to converge.
 * @param z_next The complex point after the Newton-Raphson iteration.
 * @param z The complex point before the Newton-Raphson iteration.
 * @param f(z) The value of the function f(z) at the point z.
 * @param f'(z) The value of the derivative of f(z) at the point z.
 * @param EPSILON The minimum change in z to consider convergence.
 */
void	newton_render(t_fractol *data)
{
	int			iter;
	t_complex	z_next;

	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (t_complex_abs(f_prime(data->z)) == 0)
			break ;
		z_next = subtract(data->z, divide(f(data->z), f_prime(data->z)));
		if (t_complex_abs(subtract(z_next, data->z)) < EPSILON || \
			t_complex_abs(f(data->z)) <= EPSILON)
			break ;
		data->z = z_next;
		iter++;
	}
	mlx_put_pixel(data->image, data->x, data->y, set_color(iter, data));
}

/**
 * @brief newton_fractal used for mapping complex plane to the image plane
 * @param data is the fractol struct that contains the image and the color
 * @param width is the width of the image
 * @param height is the height of the image
 * @param zoom is a value that we can change to zoom in and out of the fractal
 * @param x @param y are the coordinates of the pixel
 * @param real @param imaginary are parts of the complex number
*/
void	newton_fractal(t_fractol *data)
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
			newton_render(data);
			data->x++;
		}
		data->y++;
	}
}
