#include <stdio.h>

int main() {
    int numbers[5];  // Create an array to hold the numbers

    printf("Enter 5 numbers:\n");

    // Loop to take input from the user and store in the array
    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);  // Read a number and store in the array
    }

    // Print the array to verify the input
    printf("Numbers entered: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
