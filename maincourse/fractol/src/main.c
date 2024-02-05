/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:22:47 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 20:57:57 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * @brief Print help message and exit
 * @param argv[1] - mandelbrot
 * @param argv[2] - julia
 * @param argc = 4 - julia with 2 arguments (real and imaginary)
 * @param argv[3] - burningship
 * @param argv[4] - newton
 *
*/
void	parse_arguments(int argc, char *argv[])
{
	if (argc == 1 || argv[1][1] != '\0')
		print_help(EXIT_FAILURE);
	if (argv[1][0] != '1' && \
		argv[1][0] != '2' && \
		argv[1][0] != '3' && \
		argv[1][0] != '4')
		print_help(EXIT_FAILURE);
	if (argv[1][0] == '2' && argc < 4)
		print_help(EXIT_FAILURE);
}

t_fractol	*initialize_frctl(void)
{
	t_fractol	*frctl;

	frctl = (t_fractol *)malloc(sizeof(t_fractol));
	if (!frctl)
	{
		perror("malloc\n");
		exit(EXIT_FAILURE);
	}
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	frctl->image = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);
	frctl->min_real = -2.0;
	frctl->max_real = 2.0;
	frctl->min_imaginary = -2;
	frctl->max_imaginary = 2;
	frctl->zoom = 1.0;
	frctl->frctl_color = 1;
	return (frctl);
}

void	draw_fractal(t_fractol *frctl, int argc, char *argv[])
{
	frctl->width = WIDTH;
	frctl->height = HEIGHT;
	if (argv[1][0] == '1')
	{
		frctl->fractal_type = 1;
		mandelbrot(frctl);
	}
	else if (argv[1][0] == '2' && argc == 4)
	{
		frctl->fractal_type = 2;
		julia(frctl, frctl->real = argv[2], \
			frctl->imaginary = argv[3]);
	}
	else if (argv[1][0] == '3')
	{
		frctl->fractal_type = 3;
		burning_ship(frctl);
	}
	else if (argv[1][0] == '4')
	{
		frctl->fractal_type = 4;
		newton_fractal(frctl);
	}
	else
		print_help(EXIT_FAILURE);
}

int32_t	main(int argc, char *argv[])
{
	t_fractol	*frctl;

	parse_arguments(argc, argv);
	frctl = initialize_frctl();
	draw_fractal(frctl, argc, argv);
	mlx_image_to_window(frctl->mlx, frctl->image, 0, 0);
	mlx_key_hook(frctl->mlx, &keyhook, frctl);
	mlx_scroll_hook(frctl->mlx, &mouse_scroll_wheel, frctl);
	mlx_loop(frctl->mlx);
	cleanup(frctl);
	return (EXIT_SUCCESS);
}
