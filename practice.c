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
