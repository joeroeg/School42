#include "config.h"

/**
 * @todo add julia set
 * @todo add burningship set
 * @todo add color palette
 * @todo add mouse events
 * @todo add keyboard events
 * @todo zoom in and out
 * @todo help menu if no arguments
*/

int32_t main(int argc, char *argv[])
{
	if (argc == 1 || argv[1][1] != '\0')
		print_help();

	t_fractol	*frctl = (t_fractol *)malloc(sizeof(t_fractol));
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	frctl->image = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);
	if (argv[1][0] == '1')
		mandelbrot(frctl, WIDTH, HEIGHT);
	else if (argv[1][0] == '2' && argc == 4)
		julia(frctl, WIDTH, HEIGHT, argv[1], argv[2]);
	else
		print_help();
	mlx_image_to_window(frctl->mlx, frctl->image, 0, 0);
	mlx_loop(frctl->mlx);
	mlx_terminate(frctl->mlx);
	return (EXIT_SUCCESS);
}
/*
1. mlx_init
2. mlx_new_image
3. mlx_image_to_window
4. mlx_put_pixel
5. mlx_scroll_hook
6. mlx_loop
7. mlx_terminate
*/
