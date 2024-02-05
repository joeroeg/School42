#include "config.h"

#define EPSILON 1e-1

// Function f(z) = z^3 - 1
complex f(complex z) {
    return add(multiply(multiply(z, z), z), (complex){-1, 0});
}

// Derivative of f, f'(z) = 3z^2
complex f_prime(complex z) {
    return multiply((complex){3, 0}, multiply(z, z));
}

void newton_render(complex z, t_fractol *frctl, int x, int y) {
    int iterations = 0;
    complex f_z, f_prime_z, z_next;
    do {
        f_z = f(z);
        f_prime_z = f_prime(z);
        if (complex_abs(f_prime_z) == 0) break; // Avoid division by zero

        // Newton's method step: z_next = z - f(z) / f'(z)
        z_next = subtract(z, divide(f_z, f_prime_z));

        if (complex_abs(subtract(z_next, z)) < EPSILON) break; // Convergence check

        z = z_next;
        iterations++;
    } while (iterations < MAX_ITERATIONS && complex_abs(f_z) > EPSILON);

    // Coloring based on iterations or root converged to
    mlx_put_pixel(frctl->image, x, y, set_color(iterations));
}

void newton_fractal(t_fractol *frctl, int width, int height) {
    double minReal = -2.0, maxReal = 2.0, minImaginary = -2.0, maxImaginary = 2.0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = minReal + (x / (width - 1.0)) * (maxReal - minReal);
            double imaginary = minImaginary + (y / (height - 1.0)) * (maxImaginary - minImaginary);
            complex z = {real, imaginary};
            newton_render(z, frctl, x, y);
        }
    }
}
