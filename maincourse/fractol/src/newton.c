/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:23:02 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 21:01:44 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

#define EPSILON 1e-1

/**
 * Calculates the value of the function f(z) for a given t_complex number z.
 * This function is part of the Newton fractal rendering process,
 * where we are interested in finding the roots of t_complex functions.
 *
 * The specific function f(z) used in this context is defined as:
 * f(z) = z^3 - 1
 *
 * @param z The t_complex number input for which f(z) is to be calculated.
 * @return The value of f(z) as a t_complex number.
 */
t_complex	f(t_complex z)
{
	return (add(multiply(multiply(z, z), z), (t_complex){-1, 0}));
}

/**
 * Calculates the derivative of the function f(z),
 * 		denoted as f'(z), for a given t_complex number z.
 * The derivative is essential in the Newton-Raphson method for finding roots,
 * 		as it is used to perform iterations towards a root.
 *
 * For the function f(z) = z^3 - 1, its derivative f'(z) is:
 * f'(z) = 3z^2
 *
 * @param z The t_complex number input for which f'(z) is to be calculated.
 * @return The derivative of f(z) at the point z, as a t_complex number.
 */
t_complex	f_prime(t_complex z)
{
	return ((multiply((t_complex){3, 0}, multiply(z, z))));
}

/**
 * Renders a pixel of the Newton fractal based on the Newton-Raphson method for finding roots of t_complex functions.
 *
 * The Newton-Raphson iteration formula used here is:  * z_next = z - f(z) / f'(z),
 * where z is the current estimate of the root, f(z) is the function for which we seek roots, and f'(z) is the derivative of f(z).
 *
 * For this implementation, the function f(z) is defined as z^3 - 1, sand its derivative, f'(z), is 3z^2.
 * Thus, the iteration formula simplifies to: sz_next = z - (z^3 - 1) / (3z^2).
 *
 * Parameters:
 * - z: The initial guess for the root, represented as a t_complex number.
 * - frctl: A pointer to the fractal structure, which includes details like the image buffer and color settings.
 * - x, y: The coordinates of the pixel to render.
 *
 * The iteration process continues until one of the following conditions is met:
 * - The magnitude of the difference between successive iterations (z and z_next) is less than a defined epsilon, indicating convergence.
 * - The number of iterations exceeds a maximum limit, indicating divergence or slow convergence.
 * - The derivative f'(z) becomes zero, to avoid division by zero errors.
 *
 * The pixel's color is determined based on the number of iterations performed or the specific root the method converges to.
 */
void	newton_render(t_complex z, t_fractol *frctl, int x, int y)
{
	int			iterations;
	t_complex	f_z;
	t_complex	f_prime_z;
	t_complex	z_next;

	iterations = 0;
	do
	{
		f_z = f(z);
	f_prime_z = f_prime(z);
	if (t_complex_abs(f_prime_z) == 0)
		break ;
	z_next = subtract(z, divide(f_z, f_prime_z));
	if (t_complex_abs(subtract(z_next, z)) < EPSILON)
		break ;
	z = z_next;
	iterations++;
	}
	while (iterations < MAX_ITERATIONS && t_complex_abs(f_z) > EPSILON);
	mlx_put_pixel(frctl->image, x, y, set_color(iterations, frctl));
}

/**
 * @brief newton_fractal is responsible for mapping the t_complex plane to the image plane and calling newton_render for each pixel
 * @param frctl is the fractol struct that contains the image and the color
 * @param width is the width of the image
 * @param height is the height of the image
 * @param zoom is a value that we can change to zoom in and out of the fractal
 * @param x @param y are the coordinates of the pixel
 * @param real @param imaginary are the real and imaginary parts of the t_complex number
*/
void	newton_fractal(t_fractol *frctl)
{
	double		real;
	double		imaginary;
	t_complex	z;

	frctl->y = 0;
	while (frctl->y < frctl->height)
	{
		frctl->x = 0;
		while (frctl->x < frctl->width)
		{
			real = frctl->min_real + (frctl->x / (frctl->width - 1.0)) * \
				(frctl->max_real - frctl->min_real) / frctl->zoom;
			imaginary = frctl->min_imaginary + (frctl->y / (frctl->height - 1.0)) * \
				(frctl->max_imaginary - frctl->min_imaginary) / frctl->zoom;
			z.real = real;
			z.imag = imaginary;
			newton_render(z, frctl, frctl->x, frctl->y);
			frctl->x++;
		}
		frctl->y++;
	}
}
