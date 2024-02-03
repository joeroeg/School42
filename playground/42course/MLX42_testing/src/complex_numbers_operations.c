#include "config.h"

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

double complex_abs(complex z) {
    return sqrt(z.real * z.real + z.imag * z.imag);
}
