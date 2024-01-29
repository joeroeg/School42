#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# define WIDTH 800
# define HEIGHT 600
# define THREAD_WIDTH 5
# define THREAD_NUMBER 120

typedef struct s_fractol
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			x;
	int			y;
	int			y_max;
	int			frctl_fct;
	int			iter;
	int			iter_max;
	double		zoom;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		new_r;
	double		new_i;
	int			frctl_color;
}	t_fractol;


// void	mandelbrot_pthread(t_fractol *frctl);

void	mandelbrot_init(t_fractol *frctl);
void	mandelbrot(t_fractol *frctl);
uint32_t	set_color(int iter, t_fractol	*frctl);

#endif
