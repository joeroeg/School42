/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:53:01 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 21:01:13 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	burning_ship_render(t_complex c, t_fractol *frctl, int x, int y)
{
	int			n;
	t_complex	z;
	t_complex	z_abs;

	n = 0;
	z.real = 0;
	z.imag = 0;
	while (n < MAX_ITERATIONS)
	{
		z_abs.real = fabs(z.real);
		z_abs.imag = fabs(z.imag);
		z.real = z_abs.real * z_abs.real - z_abs.imag * z_abs.imag + c.real;
		z.imag = 2 * z_abs.real * z_abs.imag + c.imag;
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		n++;
	}
	if (n == MAX_ITERATIONS)
		mlx_put_pixel(frctl->image, x, y, 0xFF);
	else
		mlx_put_pixel(frctl->image, x, y, set_color(n, frctl));
}

void	burning_ship(t_fractol *frctl)
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
			c.real = real;
			c.imag = imaginary;
			burning_ship_render(c, frctl, frctl->x, frctl->y);
			frctl->x++;
		}
		frctl->y++;
	}
}
