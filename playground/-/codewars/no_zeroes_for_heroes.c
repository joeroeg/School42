/*
Numbers ending with zeros are boring.
They might be fun in your world, but not here.
Get rid of them. Only the ending ones.

1450 -> 145
960000 -> 96
1050 -> 105
-1050 -> -105
Zero alone is fine, don't worry about it. Poor guy anyway

gcc practice.c -lm && ./a.out
*/

#include <stdio.h>

int no_boring_zeros(int n) {
    if (n == 0)  // Return zero as is
        return 0;

    while (n % 10 == 0)
        n /= 10;

    return n;
}

int main() {
    int num1 = 1450;
    int num2 = 960000;
    int num3 = 1050;
    int num4 = -1050;

    printf("%d -> %d\n", num1, no_boring_zeros(num1));
    printf("%d -> %d\n", num2, no_boring_zeros(num2));
    printf("%d -> %d\n", num3, no_boring_zeros(num3));
    printf("%d -> %d\n", num4, no_boring_zeros(num4));

    return 0;
}