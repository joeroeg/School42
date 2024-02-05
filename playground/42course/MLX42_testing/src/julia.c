#include "config.h"

void julia_render(complex z, t_fractol *frctl, int x, int y, complex c) {
    int n;
    for (n = 0; n < MAX_ITERATIONS; n++) {
        if (complex_abs(z) > 2.0)
            break; // Point escapes to infinity
        z = add(multiply(z, z), c);
    }

    if (n == MAX_ITERATIONS)
        mlx_put_pixel(frctl->image, x, y, 0xFF);
    else
        mlx_put_pixel(frctl->image, x, y, set_color(n));
}

void julia(t_fractol *frctl, int width, int height, char *real, char *imaginary) {
    double minReal = -2.0, maxReal = 2.0, minImaginary = -1.5, maxImaginary = 1.5;
	double realPart = ft_atof(real);
    double imagPart = ft_atof(imaginary);
    complex c = {realPart, imagPart};

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = minReal + (x / (width - 1.0)) * (maxReal - minReal);
            double imaginary = minImaginary + (y / (height - 1.0)) * (maxImaginary - minImaginary);
            complex z = {real, imaginary};
            julia_render(z, frctl, x, y, c);
        }
    }
}
