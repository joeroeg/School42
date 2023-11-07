#include <stdio.h>

int main() {
    char arr[] = {'H', 'e', 'l', 'l', 'o'};
    char str[] = "Hello"; // Automatically null-terminated

    // Traversing a character array
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", arr[i]);
    }

    printf("\n");

    // Traversing a string
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }

    return 0;
}
