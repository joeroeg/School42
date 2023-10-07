#include <stdio.h>
#include <ctype.h>

int getint(int *n) {
    int c, sign;

    // Skip whitespace characters
    while ((c = getchar()) == ' ' || c == '\t' || c == '\n')
        ;

    // Check for EOF or invalid input
    if (c == EOF)
        return EOF;

    // Check for a sign
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getchar();

    // Initialize the result variable
    *n = 0;

    // Read the integer part
    while (isdigit(c)) {
        *n = (*n * 10) + (c - '0');
        c = getchar();
    }

    // Apply the sign to the result
    *n *= sign;

    // Unget the non-digit character back to the input stream
    ungetc(c, stdin);

    return *n;
}

#define SIZE 10

int main() {
    int n, v, array[SIZE];

    for (n = 0; n < SIZE && getint(&v) != EOF; n++)
        array[n] = v;

    for (int i = 0; i < n; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    return 0;
}
