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
 * Generates RGBA color for fractal pixel based on iteration count (iter).
 * Selects color scheme based on data->data_color:
 *   1 = R→GB, 2 = B→GR, 3 = G→RB.
 *
 * @param iter Iteration count to infinity escape speed.
 * @param data -> t_fractol with fractal color settings.
 *
 * Uses normalized iter depth (t) for color gradation:
 * - Color calculated via polynomial(f) of t, scaled 0-255.
 * - Returns 32-bit RGBA (alpha=255).
 *
 * @return uint32_t Color in RGBA.
 * @see https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set
 */
uint32_t	set_color(int iter, t_fractol *data)
{
	int			r;
	int			g;
	int			b;
	double		t;

	t = (double)iter / MAX_ITERATIONS;
	if (data->data_color == 1)
	{
		r = (int)(9 * (1 - t) * pow(t, 3) * 255);
		g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (data->data_color == 2)
	{
		r = (int)(8.5 * pow((1 - t), 3) * t * 255);
		g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		b = (int)(9 * (1 - t) * pow(t, 3) * 255);
	}
	if (data->data_color == 3)
	{
		r = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		g = (int)(8.5 * pow((1 - t), 3) * t * 255);
		b = (int)(9 * (1 - t) * pow(t, 3) * 255);
	}
	return (get_rgba(r, g, b, 255));
}
