#include "config.h"

void burning_ship_render(complex c, t_fractol *frctl, int x, int y) {
    complex z = {0, 0};
    int n;
    for (n = 0; n < MAX_ITERATIONS; n++) {
        // Create complex numbers with the absolute values of real and imaginary parts
        complex z_abs = {fabs(z.real), fabs(z.imag)};

        // Properly use the created complex number
        z = add(multiply(z_abs, z_abs), c);

        if (complex_abs(z) > 2.0)
            break; // Point escapes to infinity
    }

    if (n == MAX_ITERATIONS)
        mlx_put_pixel(frctl->image, x, y, 0xFF); // This might need to be adapted to your actual pixel setting function
    else
        mlx_put_pixel(frctl->image, x, y, set_color(n)); // Adapt this as well
}


void burning_ship(t_fractol *frctl, int width, int height) {
    double minReal = -2.0, maxReal = 2.0, minImaginary = -2.0, maxImaginary = 2.0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = minReal + (x / (width - 1.0)) * (maxReal - minReal);
            double imaginary = minImaginary + (y / (height - 1.0)) * (maxImaginary - minImaginary);
            complex c = {real, imaginary};
            burning_ship_render(c, frctl, x, y);
        }
    }
}
