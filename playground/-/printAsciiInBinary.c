#include <stdio.h>

/*
Outer Loop (ASCII Values):

The outer loop iterates from 0 to 127, covering all ASCII values.
Printing Character, ASCII Value, and Binary Representation:

For each ASCII value, it prints the character and its ASCII value using printf.
To print the binary representation of the ASCII value:
It uses an inner loop to traverse through the 8 bits of the ASCII value.
It starts with the leftmost bit (most significant bit) and moves to the rightmost bit (least significant bit).
It uses bitwise shifting (>>) and bitwise AND (&) operations to isolate each bit.
For each bit, it prints the result (0 or 1) using printf.
*/

void printAsciiInBinary() {
    for (int i = 0; i <= 127; i++) {
        printf("Character: %c | ASCII Value: %d | Binary: ", i, i);
        for (int j = 7; j >= 0; j--) {
            printf("%d", (i >> j) & 1);
        }
        printf("\n");
    }
}

int main() {
    printAsciiInBinary();
    return 0;
}
