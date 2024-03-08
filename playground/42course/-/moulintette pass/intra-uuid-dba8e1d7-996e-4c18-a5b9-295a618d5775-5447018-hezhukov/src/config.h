/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:11:02 by hezhukov          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:47 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

/**
 * @brief Generic macros for the fractol program.
 * @param MAX_ITERATIONS The maximum of iterations in the fractal calculations.
 * @param WIDTH The width of the window.
 * @param HEIGHT The height of the window.
*/
# define MAX_ITERATIONS 36
# define EPSILON 1e-1
# define WIDTH 1000
# define HEIGHT 1000
# define BLACK 0xFF

/**
 * @brief Complex number structure that holds the real and imaginary parts.
 * @param real The real part of the complex number.
 * @param imag The imaginary part of the complex number.
*/
typedef struct complex
{
	double	real;
	double	imag;
}	t_complex;

/**
 * @brief The color structure that holds the RGB values for the fractal.
 * @param r The red value of the color.
 * @param g The green value of the color.
 * @param b The blue value of the color.
 * @param frctl_r The red value of the fractal.
 * @param frctl_g The green value of the fractal.
 * @param frctl_b The blue value of the fractal.
 * @param escape_r The red value of the escape.
 * @param escape_g The green value of the escape.
 * @param escape_b The blue value of the escape.
*/
typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			frctl_r;
	int			frctl_g;
	int			frctl_b;
	int			escape_r;
	int			escape_g;
	int			escape_b;
}	t_color;

/**
 * @brief The structure that holds all the data needed to draw a fractal.
 * @param image The image to be drawn on.
 * @param mlx The MLX42 library.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param x The x coordinate of the window.
 * @param y The y coordinate of the window.
 * @param fractal_type The type of fractal to be drawn.
 * @param zoom The zoom factor of the fractal.
 * @param min_real The minimum real part of the complex plane.
 * @param max_real The maximum real part of the complex plane.
 * @param min_imaginary The minimum imaginary part of the complex plane.
 * @param max_imaginary The maximum imaginary part of the complex plane.
 * @param real The real part of the complex number from argv[2].
 * @param imaginary The imaginary part of the complex number from argv[3].
 * @param c The constant to be used in the Julia and Mandelbroat sets.
 * @param z The complex number to be used in all fractal calculations.
 * @param data_color The color of the fractal.
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
	t_complex	c;
	t_complex	z;
	int			data_color;
	t_color		color;
}	t_fractol;

/**
 * @brief The functions to draw the fractals.
 * @param data The fractal structure.
 *
*/
void		draw_fractal(t_fractol *data, int argc, char *argv[]);
void		mandelbrot(t_fractol *data);
void		mandelbrot_render(t_fractol *data);
void		julia(t_fractol *data);
void		julia_render(t_fractol *data);
void		burning_ship(t_fractol *data);
void		burning_ship_render(t_complex c, t_fractol *data);
void		newton_fractal(t_fractol *data);
void		newton_render(t_fractol *data);

/**
 * @brief The complex number operations.
 * @param n1 The first complex number.
 * @param n2 The second complex number.
 * @return The result of the operation.
*/
t_complex	add(t_complex n1, t_complex n2);
t_complex	subtract(t_complex n1, t_complex n2);
t_complex	multiply(t_complex n1, t_complex n2);
t_complex	divide(t_complex n1, t_complex n2);
double		t_complex_abs(t_complex z);

/**
 * @brief The color operations.
 * @param iter The number of iterations is taken to calculate the color
 * because the color depends on the number of iterations.
 * @param data The fractal structure.
*/
uint32_t	set_color(int iter, t_fractol *data);

/**
 * @brief The helper functions.
 * @param should_exit The flag to exit the program with EXIT_FAILURE or not.
 *
*/
int			print_help(int should_exit);
double		ft_atof(const char *str);
void		cleanup(t_fractol *data);

/**
 * @brief The hooks for the MLX42 library.
 * @param x The x coordinate of the mouse.
 * @param y The y coordinate of the mouse.
 * @param param The fractal structure.
 * @param xdelta The x coordinate of the mouse wheel.
 * @param ydelta The y coordinate of the mouse wheel.
*/
void		mouse_scroll_wheel(double xdelta, double ydelta, void *param);
void		keyhook(mlx_key_data_t keydata, void *param);
void		color_shift(keys_t key, t_fractol *data);
void		mouse_cursor_hook(double xpos, double ypos, void *param);
#endif
