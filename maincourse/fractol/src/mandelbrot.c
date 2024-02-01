#include "fractol.h"

void	mandelbrot_init(t_fractol *frctl)
{
	frctl->iter_max = 200;
	frctl->zoom = 300;
	frctl->xmin = -2;
	frctl->xmax = 1.2;
	frctl->ymin = -1.2;
	frctl->ymax = 1.2;
	frctl->frctl_color = 1;
}

void	mandelbrot_calc(t_fractol *frctl)
{
	frctl->z_r = 0;
	frctl->z_i = 0;
	frctl->iter = 0;
	while (pow(frctl->z_r, 2) + pow(frctl->z_i, 2) < 4
		&& frctl->iter < frctl->iter_max)
	{
		frctl->new_r = pow(frctl->z_r, 2) - pow(frctl->z_i, 2) + frctl->c_r;
		frctl->new_i = 2 * frctl->z_i * frctl->z_r + frctl->c_i;
		frctl->z_r = frctl->new_r;
		frctl->z_i = frctl->new_i;
		frctl->iter++;
	}
	if (frctl->iter == frctl->iter_max)
		mlx_put_pixel(frctl->img, frctl->x, frctl->y, 0xFF);
	else
		mlx_put_pixel(frctl->img, frctl->x, frctl->y,
			set_color(frctl->iter, frctl));
}

void mandelbrot(t_fractol *frctl)
{
    double xdelta = frctl->xmax - frctl->xmin;
    double ydelta = frctl->ymax - frctl->ymin;

    frctl->x = 0;
    while (frctl->x < WIDTH)
    {
        frctl->y = 0;
        while (frctl->y < HEIGHT)
        {
            frctl->c_r = frctl->xmin + frctl->x * xdelta / WIDTH;
            frctl->c_i = frctl->ymin + frctl->y * ydelta / HEIGHT;
            mandelbrot_calc(frctl);
            frctl->y++;
        }
        frctl->x++;
    }
    mlx_image_to_window(frctl->mlx, frctl->img, 0, 0);
}
