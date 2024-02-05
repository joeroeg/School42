/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:17:45 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:16:28 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * Generates 32-bit RGBA color from 8-bit RGB and A components.
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @param a Alpha component (0-255). (255 = opaque, 0 = transparent).
*/
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * Linearly interpolates between two values.
 * @param start The start value.
 * @param end The end value.
 * @param t The interpolation value.
*/
// Linearly interpolates between two values.
float	lerp(float start, float end, float t)
{
	return (start + t * (end - start));
}

uint32_t	calculate_color(t_fractol *data, int iter)
{
	float	t;

	t = (float)iter / MAX_ITERATIONS;
	data->color.r = lerp(data->color.frctl_r, data->color.escape_r, t);
	data->color.g = lerp(data->color.frctl_g, data->color.escape_g, t);
	data->color.b = lerp(data->color.frctl_b, data->color.escape_b, t);
	return (get_rgba(data->color.r, data->color.g, data->color.b, 255));
}

/**
 * Sets the color of the fractal.
 * @param iter The number of iterations.
 * @param data The fractal data.
*/
uint32_t	set_color(int iter, t_fractol *data)
{
	data->color.escape_r = 0;
	data->color.escape_g = 0;
	data->color.escape_b = 0;
	if (data->data_color == 1)
	{
		data->color.frctl_r = 255;
		data->color.frctl_g = 0;
		data->color.frctl_b = 0;
	}
	if (data->data_color == 2)
	{
		data->color.frctl_r = 0;
		data->color.frctl_g = 255;
		data->color.frctl_b = 0;
	}
	if (data->data_color == 3)
	{
		data->color.frctl_r = 0;
		data->color.frctl_g = 0;
		data->color.frctl_b = 255;
	}
	return (calculate_color(data, iter));
}
