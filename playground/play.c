#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <time.h> // For time() function
#include <unistd.h> // For sleep()

#define ITERATIONS 20

int mandelbrot(double complex c) {
    double complex z = 0;
    int n;
    for (n = 0; n < ITERATIONS; n++) {
        if (cabs(z) > 2.0) break;
        z = z * z + c;
    }
    return n;
}

char getRandomChar() {
    return "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*(){}|<>?:~"[rand() % 70];
}

int main() {
    int width = 100, height = 100;
    double minReal = -2.0, maxReal = 1.0, minImaginary = -1.5, maxImaginary = 1.5;

    srand(time(NULL));

    while (1) {
        system("clear");

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                double real = minReal + (x / (width - 1.0)) * (maxReal - minReal);
                double imaginary = minImaginary + (y / (height - 1.0)) * (maxImaginary - minImaginary);
                double complex c = real + imaginary * I;
                int m = mandelbrot(c);
                printf("%c", (m == ITERATIONS) ? getRandomChar() : ' ');
            }
            printf("\n");
        }

        usleep(100000);
    }

    return 0;
}
