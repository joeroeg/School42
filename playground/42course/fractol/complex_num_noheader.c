/*
	This is an example of a simple Mandelbrot set generator using complex numbers without the complex.h header file.
	The program generates a text-based representation of the Mandelbrot set by iterating over each pixel in the image and determining if the corresponding point in the complex plane belongs to the Mandelbrot set.
*/

#include <stdio.h>
#include <math.h>

#define ITERATIONS 10

typedef struct complex {
    float real;
    float imag;
} complex;

complex add(complex n1, complex n2) {
	complex temp;
	temp.real = n1.real + n2.real;
	temp.imag = n1.imag + n2.imag;
	return (temp);
}

complex subtract(complex n1, complex n2) {
	complex temp;
	temp.real = n1.real - n2.real;
	temp.imag = n1.imag - n2.imag;
	return (temp);
}

complex multiply(complex n1, complex n2) {
	complex temp;
	temp.real = n1.real * n2.real - n1.imag * n2.imag;
	temp.imag = n1.real * n2.imag + n1.imag * n2.real;
	return (temp);
}

complex divide(complex n1, complex n2) {
	complex temp;
	temp.real = (n1.real * n2.real + n1.imag * n2.imag) / (n2.real * n2.real + n2.imag * n2.imag);
	temp.imag = (n2.real * n1.imag - n1.real * n2.imag) / (n2.real * n2.real + n2.imag * n2.imag);
	return (temp);
}

float complex_abs(complex z) {
    return sqrt(z.real * z.real + z.imag * z.imag);
}


int mandelbrot(complex c) {
    complex z = {0, 0};
    int n;
    for (n = 0; n < ITERATIONS; n++) {
        if (complex_abs(z) > 2.0) break; // Point escapes to infinity
	z = add(multiply(z, z), c);
    }
    return n; // Number of iterations before escape
}

int main()
{
    // Set the size of the image and the scale for the complex plane
    int width = 50, height = 50;
    double minReal = -2.0, maxReal = 1.0, minImaginary = -1.0, maxImaginary = 1.0;

    // Iterate over each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double real = minReal + (x / (width - 1.0)) * (maxReal - minReal);
            double imaginary = minImaginary + (y / (height - 1.0)) * (maxImaginary - minImaginary);
            complex c = add((complex){real, 0}, (complex){0, imaginary});
            int m = mandelbrot(c);

            // Print a character based on the return value
            printf("%s", (m ==  ITERATIONS) ? "." : " "); // Simple text-based output
        }
        printf("\n");
    }
    return 0;
}


