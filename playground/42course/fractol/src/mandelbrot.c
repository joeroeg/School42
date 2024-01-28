#include "fractol.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;
	size_t	i;

	if (!src || !dst)
		return (dst);
	c_dst = (char *) dst;
	c_src = (char *) src;
	i = 0;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (c_dst);
}

void	mandelbrot_init(t_fractol *frctl)
{
	frctl->iter_max = 25;
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

void	*mandelbrot(void *param)
{
	t_fractol	*frctl;
	int			tmp;
	double		xdelta;
	double		ydelta;

	frctl = (t_fractol *)param;
	xdelta = frctl->xmax - frctl->xmin;
	ydelta = frctl->ymax - frctl->ymin;
	tmp = frctl->y;
	frctl->x = 0;
	while (frctl->x < WIDTH)
	{
		frctl->y = tmp;
		while (frctl->y < frctl->y_max)
		{
			frctl->c_r = frctl->xmin + frctl->x * xdelta / WIDTH;
			frctl->c_i = frctl->ymin + frctl->y * ydelta / HEIGHT;
			mandelbrot_calc(frctl);
			frctl->y++;
		}
		frctl->x++;
	}
	return (param);
}

void	mandelbrot_pthread(t_fractol *frctl)
{
	t_fractol	t_param[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		printf("i: %d\n", i);
		ft_memcpy((void *)&t_param[i], (void *)frctl, sizeof(t_fractol));
		t_param[i].y = THREAD_WIDTH * i;
		t_param[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &t_param[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_image_to_window(frctl->mlx, frctl->img, 0, 0);
}
