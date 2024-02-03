#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define MAX_ITERATIONS 18
#define WIDTH 800
#define HEIGHT 800

typedef struct complex {
    double real;
    double imag;
} complex;


typedef struct s_fractol
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	// int			x;
	// int			y;
	// int			y_max;
	// int			frctl_fct;
	// int			iter;
	// int			iter_max;
	// double		zoom;
	// double		xmin;
	// double		xmax;
	// double		ymin;
	// double		ymax;
	// double		c_r;
	// double		c_i;
	// double		z_r;
	// double		z_i;
	// double		new_r;
	// double		new_i;
	// int			frctl_color;
}	t_fractol;

// fractal functions
void mandelbrot(t_fractol *frctl, int width, int height);
void mandelbrot_render(complex c, t_fractol *frctl, int x, int y);
void julia(t_fractol *frctl, int width, int height, char *real, char *imaginary);
void julia_render(complex z, t_fractol *frctl, int x, int y, complex c);


// complex numbers operations
complex add(complex n1, complex n2);
complex subtract(complex n1, complex n2);
complex multiply(complex n1, complex n2);
complex divide(complex n1, complex n2);
double complex_abs(complex z);

// color operations
uint32_t	set_color(int iter);

// utility functions
void	print_help(void);

#endif
