#include "fractol.h"

void	mlx_setup(t_fractol *frctl)
{
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	frctl->img = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);
}

int32_t	main(int32_t argc, const char *argv[])
{
	t_fractol	*frctl = (t_fractol *)malloc(sizeof(t_fractol));
	(void) argc;
	(void) argv;

	mlx_setup(frctl);
	mandelbrot_init(frctl);
	mandelbrot_pthread(frctl);
	mlx_loop(frctl->mlx);
	mlx_terminate(frctl->mlx);
	return (EXIT_SUCCESS);
}
