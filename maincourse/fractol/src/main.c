/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:22:47 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:54 by hezhukov         ###   ########.fr       */
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

t_fractol	*initialize_data(void)
{
	t_fractol	*data;

	data = (t_fractol *)malloc(sizeof(t_fractol));
	if (!data)
	{
		perror("malloc\n");
		exit(EXIT_FAILURE);
	}
	data->width = WIDTH;
	data->height = HEIGHT;
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->min_real = -2.0;
	data->max_real = 2.0;
	data->min_imaginary = -2;
	data->max_imaginary = 2;
	data->zoom = 1.0;
	data->data_color = 1;
	return (data);
}

void	draw_fractal(t_fractol *data, int argc, char *argv[])
{
	if (argv[1][0] == '1')
	{
		data->fractal_type = 1;
		mandelbrot(data);
	}
	else if (argv[1][0] == '2' && argc == 4)
	{
		data->fractal_type = 2;
		data->c.real = ft_atof(argv[2]);
		data->c.imag = ft_atof(argv[3]);
		julia(data);
	}
	else if (argv[1][0] == '3')
	{
		data->fractal_type = 3;
		burning_ship(data);
	}
	else if (argv[1][0] == '4')
	{
		data->fractal_type = 4;
		newton_fractal(data);
	}
	else
		print_help(EXIT_FAILURE);
}

int32_t	main(int argc, char *argv[])
{
	t_fractol	*data;

	parse_arguments(argc, argv);
	data = initialize_data();
	draw_fractal(data, argc, argv);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	mlx_key_hook(data->mlx, &keyhook, data);
	mlx_scroll_hook(data->mlx, &mouse_scroll_wheel, data);
	mlx_loop(data->mlx);
	cleanup(data);
	return (EXIT_SUCCESS);
}
