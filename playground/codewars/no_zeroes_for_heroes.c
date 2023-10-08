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
#include <math.h>

int main() {
    int number = 123456789;
    int newNumber = 0;
    int digitPosition = 1;  // To keep track of the current digit position

    while (number > 0) {
        int digit = number % 10;
        if (digitPosition == 4) {
            digit = 0;  // Replace with the desired new value
        } else if (digitPosition == 7) {
            digit = 0;  // Replace with the desired new value
        }
        newNumber = newNumber + digit * pow(10, digitPosition - 1);
        number /= 10;
        digitPosition++;
    }

    printf("Modified number: %d\n", newNumber);
    return 0;
}
