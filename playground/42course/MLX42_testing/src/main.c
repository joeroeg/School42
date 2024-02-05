#include "config.h"





int32_t main(int argc, char *argv[])
{
	if (argc == 1 || argv[1][1] != '\0')
		print_help();

	t_fractol	*frctl = (t_fractol *)malloc(sizeof(t_fractol)); // malloc shoule be moved to the other place
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	frctl->image = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);
	if (argv[1][0] == '1')
		mandelbrot(frctl, WIDTH, HEIGHT);
	else if (argv[1][0] == '2' && argc == 4)
		julia(frctl, WIDTH, HEIGHT, argv[2], argv[3]);
	else if (argv[1][0] == '3')
		burning_ship(frctl, WIDTH, HEIGHT);
	else if (argv[1][0] == '4')
		newton_fractal(frctl, WIDTH, HEIGHT);
	else
		print_help();
	mlx_image_to_window(frctl->mlx, frctl->image, 0, 0);
	mlx_key_hook(frctl->mlx, &keyhook, frctl);
	mlx_scroll_hook(frctl->mlx, &mouse_scroll_whell, frctl);
	mlx_loop(frctl->mlx);
	cleanup(frctl);
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
