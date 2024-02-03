In C, complex numbers are supported by the Standard Library through the complex data type and a set of functions for complex arithmetic, defined in the `<complex.h>` header file. To work with complex numbers in C, you first need to include this header file in your program.

Here's a basic guide on how to build and use complex numbers in C:

### Including the Complex Header

To use complex numbers, include the `<complex.h>` header at the beginning of your program:

```c
#include <complex.h>
```

### Declaring Complex Variables

You can declare complex variables using the `double complex` type for double-precision complex numbers or `float complex` for single-precision. The `long double complex` type is also available for extended precision complex numbers.

```c
double complex z1;
float complex z2;
```

### Initializing Complex Variables

You can initialize complex variables using the `CMPLX`, `CMPLXF`, and `CMPLXL` macros for `double complex`, `float complex`, and `long double complex` types, respectively. Alternatively, use the `complex` function to create complex numbers:

```c
double complex z1 = 1.0 + 3.0 * I; // Using the I constant for the imaginary part
double complex z2 = CMPLX(2.0, -4.5); // Using CMPLX macro
```

### Performing Operations

The `<complex.h>` header provides functions to perform arithmetic operations, such as addition, subtraction, multiplication, division, and other complex operations like taking the absolute value, phase (argument), conjugate, exponential, logarithm, etc. Here are a few examples:

```c
double complex z1 = 1.0 + 2.0 * I;
double complex z2 = 1.0 - 2.0 * I;

// Addition
double complex sum = z1 + z2;

// Multiplication
double complex product = z1 * z2;

// Absolute value (magnitude)
double magnitude = cabs(z1);

// Phase (argument)
double phase = carg(z1);

// Conjugate
double complex conjugate = conj(z1);
```

### Printing Complex Numbers

To print complex numbers, you can use the `creal` and `cimag` functions to extract the real and imaginary parts, respectively, and then print them using `printf`:

```c
printf("Real part: %f, Imaginary part: %f\n", creal(z1), cimag(z1));
```

This is a basic introduction to using complex numbers in C. The `<complex.h>` header provides a wide range of functions to perform more complex operations, so you might want to explore further depending on your needs.

---

To work with complex numbers in C without using the `<complex.h>` header, you would typically define your own complex number structure and implement the necessary arithmetic operations. This approach is more manual but offers flexibility, especially in environments where `<complex.h>` is not available or when learning the underlying mechanics of complex number arithmetic.

### Defining a Complex Number Structure

First, you define a structure to represent complex numbers. This structure will have two components: the real part and the imaginary part. Here's how you could define it:

```c
typedef struct {
    double real;
    double imag;
} Complex;
```

### Implementing Basic Operations

Next, you implement functions for basic arithmetic operations on complex numbers, such as addition, subtraction, multiplication, and division.

#### Addition

```c
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}
```

#### Subtraction

```c
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}
```

#### Multiplication

```c
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}
```

#### Division

Division is slightly more complex because you need to calculate the conjugate of the denominator and multiply both numerator and denominator by that conjugate, then divide by the magnitude squared of the denominator.

```c
Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}
```

### Example Usage

Here's how you might use these structures and functions in a program:

```c
#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

// Function declarations
Complex add(Complex a, Complex b);
Complex subtract(Complex a, Complex b);
Complex multiply(Complex a, Complex b);
Complex divide(Complex a, Complex b);

int main() {
    Complex z1 = {2.0, 3.0};
    Complex z2 = {1.0, -4.0};

    Complex sum = add(z1, z2);
    printf("Sum: %f + %fi\n", sum.real, sum.imag);

    Complex product = multiply(z1, z2);
    printf("Product: %f + %fi\n", product.real, product.imag);

    // Add more operations as needed
    return 0;
}

// Implementations of add, subtract, multiply, divide...
```

### Note

This approach requires manual implementation of each complex number operation you wish to perform, but it's a great exercise for understanding how complex numbers work. If you're working on a project where performance and accuracy are critical, consider using the standard `<complex.h>` header for its optimized and tested implementations.
