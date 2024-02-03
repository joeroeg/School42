#include "config.h"

/**
 * @brief Calculates whether a point belongs to the Mandelbrot set.
 *
 * This function iterates on the complex number z, starting from 0, using the formula z = z^2 + c,
 * where c is a point in the complex plane. The iteration continues until the absolute value of z exceeds
 * 2.0, indicating the point does not belong to the Mandelbrot set, or until the maximum number of iterations
 * is reached. Points that remain within the escape radius of 2.0 after the maximum number of iterations are
 * considered to be part of the Mandelbrot set. The pixel at coordinates (x, y) is then colored accordingly.
 *
 * @param c The complex number representing the point in the complex plane being tested for membership in the Mandelbrot set.
 * @param frctl A pointer to the t_fractol structure, which contains the image where the result will be drawn.
 * @param x The x-coordinate of the pixel in the image corresponding to the complex number c.
 * @param y The y-coordinate of the pixel in the image corresponding to the complex number c.
 *
 * @details
 * The escape radius of 2.0 is used to determine if a point escapes to infinity. If the absolute value of z exceeds this radius,
 * it indicates that the point does not belong to the Mandelbrot set. This method colors the pixel at (x, y) based on the number
 * of iterations required to determine if the point escapes. A special color is used for points that are determined to be within
 * the Mandelbrot set (i.e., those that do not escape within the maximum number of iterations).
 */


/**
 * @todo add julia set
 *
*/
void mandelbrot(complex c, t_fractol *frctl, int x, int y) {
    complex z = {0, 0};
    int n;
    for (n = 0; n < MAX_ITERATIONS; n++) {
        if (complex_abs(z) > 2.0)
			break; // Point escapes to infinity
		z = add(multiply(z, z), c);
	}
	if (n == MAX_ITERATIONS)
		mlx_put_pixel(frctl->image, x, y, 0xFF);
	else
		mlx_put_pixel(frctl->image, x, y, set_color(n, frctl));
		// mlx_put_pixel(frctl->image, x, y, set_color(n));
}

int32_t main()
{
	t_fractol	*frctl = (t_fractol *)malloc(sizeof(t_fractol));
	frctl->mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	frctl->image = mlx_new_image(frctl->mlx, WIDTH, HEIGHT);

    // Set the size of the image and the scale for the complex plane
    double minReal = -2.0, maxReal = 1.0, minImaginary = -1.5, maxImaginary = 1.5;

    // Iterate over each pixel
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = minReal + (x / (WIDTH - 1.0)) * (maxReal - minReal);
            double imaginary = minImaginary + (y / (HEIGHT - 1.0)) * (maxImaginary - minImaginary);
            complex c = add((complex){real, 0}, (complex){0, imaginary});
            mandelbrot(c, frctl, x, y);
        }
    }
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
