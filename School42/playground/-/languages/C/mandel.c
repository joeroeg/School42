#include <stdio.h>
#include <math.h>
#include <complex.h>

#define dx 1500
#define dy 1400
#define MAX_ITER 20

int main() {
    double complex C[dy][dx];
    double complex Z;
    double X[dy][dx][MAX_ITER];
    
    // Generate complex grid C
    for (int j = 0; j < dy; j++) {
        for (int i = 0; i < dx; i++) {
            double real_part = -2.2 + i * (3.2 / dx);
            double imag_part = -1.2 + j * (2.4 / dy);
            C[j][i] = real_part + imag_part * I;
        }
    }
    
    // Iterate and generate fractal
    for (int j = 0; j < dy; j++) {
        for (int i = 0; i < dx; i++) {
            Z = 0; // Initialize Z for each point
            for (int k = 0; k < MAX_ITER; k++) {
                Z = Z * Z + C[j][i];
                X[j][i][k] = exp(-cabs(Z));
            }
        }
    }
    
    // Print results (you can save it to a file as well)
    for (int j = 0; j < dy; j++) {
        for (int i = 0; i < dx; i++) {
            printf("%lf ", X[j][i][MAX_ITER - 1]);
        }
        printf("\n");
    }
    
    return 0;
}
