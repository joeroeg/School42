/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:22:30 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 21:17:02 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	julia_render(t_complex z, t_fractol *frctl, int x, int y, t_complex c)
{
	int	n;

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

void	julia(t_fractol *frctl, char *real, char *imaginary)
{
	double		real_part;
	double		imag_part;
	t_complex	c;
	double		real_number;
	double		imaginmary_number;
	t_complex	z;

	real_part = ft_atof(real);
	imag_part = ft_atof(imaginary);
	c.real = real_part;
	c.imag = imag_part;
	frctl->y = 0;
	while (frctl->y < frctl->height)
	{
		frctl->x = 0;
		while (frctl->x < frctl->width)
		{
			real_number = frctl->min_real + (frctl->x / (frctl->width - 1.0)) * \
				(frctl->max_real - frctl->min_real) / frctl->zoom;
			imaginmary_number = frctl->min_imaginary + (frctl->y / (frctl->height - 1.0)) * \
				(frctl->max_imaginary - frctl->min_imaginary) / frctl->zoom;
			z.real = real_number;
			z.imag = imaginmary_number;
			julia_render(z, frctl, frctl->x, frctl->y, c);
			frctl->x++;
		}
		frctl->y++;
	}
}
