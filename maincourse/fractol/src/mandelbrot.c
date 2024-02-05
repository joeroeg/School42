/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:22:56 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 20:56:08 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * @brief Calculates whether a point belongs to the Mandelbrot set.
 *
 * This function iterates on the t_complex number z, starting from 0, using the formula z = z^2 + c,
 * where c is a point in the t_complex plane. The iteration continues until the absolute value of z exceeds
 * 2.0, indicating the point does not belong to the Mandelbrot set, or until the maximum number of iterations
 * is reached. Points that remain within the escape radius of 2.0 after the maximum number of iterations are
 * considered to be part of the Mandelbrot set. The pixel at coordinates (x, y) is then colored accordingly.
 *
 * @param c The t_complex number representing the point in the t_complex plane being tested for membership in the Mandelbrot set.
 * @param frctl A pointer to the t_fractol structure, which contains the image where the result will be drawn.
 * @param x The x-coordinate of the pixel in the image corresponding to the t_complex number c.
 * @param y The y-coordinate of the pixel in the image corresponding to the t_complex number c.
 *
 * @details
 * The escape radius of 2.0 is used to determine if a point escapes to infinity. If the absolute value of z exceeds this radius,
 * it indicates that the point does not belong to the Mandelbrot set. This method colors the pixel at (x, y) based on the number
 * of iterations required to determine if the point escapes. A special color is used for points that are determined to be within
 * the Mandelbrot set (i.e., those that do not escape within the maximum number of iterations).
 */

void	mandelbrot_render(t_complex c, t_fractol *frctl, int x, int y)
{
	t_complex	z;
	int			n;

	z.real = 0;
	z.imag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if (t_complex_abs(z) > 2.0)
			break ;
		z = add(multiply(z, z), c);
		n++;
	}
	if (n == MAX_ITERATIONS)
		mlx_put_pixel(frctl->image, x, y, 0xFF);
	else
		mlx_put_pixel(frctl->image, x, y, set_color(n, frctl));
}

void	mandelbrot(t_fractol *frctl)
{
	double		real;
	double		imaginary;
	t_complex	c;

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
			c = add((t_complex){real, 0}, (t_complex){0, imaginary});
			mandelbrot_render(c, frctl, frctl->x, frctl->y);
			frctl->x++;
		}
		frctl->y++;
	}
}
