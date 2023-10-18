#include <stdio.h>

int main() {
    double num1, num2;
    printf("Enter two decimal numbers: ");
    scanf("%lf %lf", &num1, &num2);

    int result = (int)num1 & (int)num2; // Logic AND
    printf("Result of AND operation: %d\n", result);

    result = (int)num1 | (int)num2; // Logic OR
    printf("Result of OR operation: %d\n", result);

    result = (int)num1 ^ (int)num2; // Logic XOR
    printf("Result of XOR operation: %d\n", result);

    result = ~(int)num1; // Logic NOT
    printf("Result of NOT operation for num1: %d\n", result);

    result = ~(int)num2; // Logic NOT
    printf("Result of NOT operation for num2: %d\n", result);

    return 0;
}
