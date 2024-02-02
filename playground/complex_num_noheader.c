#include <stdio.h>

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

int main()
{
	int width = 100, height = 100;
	complex min = {-2.0, -2.0};
	complex max = {1.0, 2.0};
	complex c;




	// complex z1 = {1.0, 3.0}, z2 = {1.0, -4.0};
	// complex sum = add(z1, z2);
	// printf("The sum: Z1 + Z2 = %.2f %+.2fi\n", sum.real, sum.imag);
	return 0;
}


