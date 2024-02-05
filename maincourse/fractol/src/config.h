/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:11:02 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/04 21:08:23 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define MAX_ITERATIONS 36
# define WIDTH 1000
# define HEIGHT 1000

typedef struct complex
{
	double	real;
	double	imag;
}	t_complex;

/**
 * @var real The real part of the t_complex number from argv[2].
 * @var imaginary The imaginary part of the complex number from argv[3].
*/
typedef struct s_fractol
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			width;
	int			height;
	int			x;
	int			y;
	int			fractal_type;
	double		zoom;
	double		min_real;
	double		max_real;
	double		min_imaginary;
	double		max_imaginary;
	char		*real;
	char		*imaginary;
	int			frctl_color;
}	t_fractol;

// fractal functions
void		draw_fractal(t_fractol *frctl, int argc, char *argv[]);
void		mandelbrot(t_fractol *frctl);
void		mandelbrot_render(t_complex c, t_fractol *frctl, int x, int y);
void		julia(t_fractol *frctl, char *real, char *imaginary);
void		julia_render(t_complex z, t_fractol *frctl, int x, int y, t_complex c); // @todo - fix this line for norminette
void		burning_ship(t_fractol *frctl);
void		burning_ship_render(t_complex c, t_fractol *frctl, int x, int y);
void		newton_fractal(t_fractol *frctl);
void		newton_render(t_complex z, t_fractol *frctl, int x, int y);

// complex numbers operations
t_complex	add(t_complex n1, t_complex n2);
t_complex	subtract(t_complex n1, t_complex n2);
t_complex	multiply(t_complex n1, t_complex n2);
t_complex	divide(t_complex n1, t_complex n2);
double		t_complex_abs(t_complex z);

// color operations
uint32_t	set_color(int iter, t_fractol *frctl);

// utility functions
int			print_help(int should_exit);
double		ft_atof(const char *str);
void		cleanup(t_fractol *frctl);

// hook functions
void		mouse_scroll_wheel(double xdelta, double ydelta, void *param);
void		keyhook(mlx_key_data_t keydata, void *param);
void		color_shift(keys_t key, t_fractol *frctl);
#endif
