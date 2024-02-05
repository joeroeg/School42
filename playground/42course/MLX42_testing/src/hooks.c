#include "config.h"

void	mouse_scroll_whell(double xdelta, double ydelta, void *param)
{
	t_fractol			*frctl;

	frctl = (t_fractol *)param;
	if (xdelta == 0)
		;
	frctl->zoom = 300;
	if (ydelta > 0)
	{
		frctl->ymin *= 0.95;
		frctl->ymax *= 0.95;
		frctl->xmin *= 0.95;
		frctl->xmax *= 0.95;
		frctl->zoom *= 0.95;
	}
	frctl->zoom = 300;
	if (ydelta < 0)
	{
		frctl->ymin *= 1.05;
		frctl->ymax *= 1.05;
		frctl->xmin *= 1.05;
		frctl->xmax *= 1.05;
		frctl->zoom *= 0.8;
	}
	mandelbrot(frctl, WIDTH, HEIGHT);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frctl;

	frctl = (t_fractol *)param;
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_LEFT))
		move(keydata.key, frctl);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_I)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_O))
		change_maxiter(keydata.key, frctl);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_R)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_G)
		|| mlx_is_key_down(frctl->mlx, MLX_KEY_B))
		color_shift(keydata.key, frctl);
	if (mlx_is_key_down(frctl->mlx, MLX_KEY_H))
		print_help();
}

void	move(keys_t key, t_fractol *frctl)
{
	if (key == MLX_KEY_UP)
	{
		frctl->ymin += 15 / frctl->zoom;
		frctl->ymax += 15 / frctl->zoom;
	}
	if (key == MLX_KEY_DOWN)
	{
		frctl->ymin -= 15 / frctl->zoom;
		frctl->ymax -= 15 / frctl->zoom;
	}
	if (key == MLX_KEY_LEFT)
	{
		frctl->xmin += 15 / frctl->zoom;
		frctl->xmax += 15 / frctl->zoom;
	}
	if (key == MLX_KEY_RIGHT)
	{
		frctl->xmin -= 15 / frctl->zoom;
		frctl->xmax -= 15 / frctl->zoom;
	}
	fract_calc(frctl);
}
