#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define ITERATIONS 10

// Function to determine if a point belongs to the Mandelbrot Set
int mandelbrot(double complex c) {
    double complex z = 0;
    int n;
    for (n = 0; n < ITERATIONS; n++) {
        if (cabs(z) > 2.0) break; // Point escapes to infinity
        z = z * z + c;
    }
    return n; // Number of iterations before escape
}

int main() {
    // Set the size of the image and the scale for the complex plane
    int width = 100, height = 100;
    double minReal = -2.0, maxReal = 1.0, minImaginary = -2, maxImaginary = 2;

    // Iterate over each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = minReal + (x / (width - 1.0)) * (maxReal - minReal);
            double imaginary = minImaginary + (y / (height - 1.0)) * (maxImaginary - minImaginary);
            double complex c = real + imaginary * I;

            int m = mandelbrot(c);

            // Print a character based on the return value
            printf("%s", (m ==  ITERATIONS) ? " " : "."); // Simple text-based output
        }
        printf("\n");
    }

    return 0;
}
