/*
A lookup table is a data structure that contains pre-calculated values or results of a function, which are then used to avoid repeated calculations in a program.
Instead of performing a time-consuming calculation repeatedly, a lookup table provides a faster way to access the result of that calculation.
In other words, it's a way of trading off memory usage for faster execution time.
In C language, a lookup table can be implemented using an array or a map (also known as a dictionary).
This is an example of using an array as a lookup table to calculate the square of a number:
*/

#include <stdio.h>

int main() {
    int lookup[10];

    for (int i = 0; i < 10; i++) {
        lookup[i] = i * i;
    }

    for (int i = 0; i < 10; i++) {
        printf("The square of %d is %d\n", i, lookup[i]);
    }

    return 0;
}
