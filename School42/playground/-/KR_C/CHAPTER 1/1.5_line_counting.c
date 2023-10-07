#include <stdio.h>

int main() /* count lines in input */
{
    int c, nl;

    nl = 0;  // Initialize the line counter to 0
    while ((c = getchar()) != EOF)  // Read characters until End of File (EOF) is encountered
        if (c == ' ')  // Check if the character is a newline character
            ++nl;  // Increment the line counter
    printf("%d\n", nl);  // Print the total number of lines counted
}

/*
Hello, this is a test.
This is the second line.
And this is the third line.
Press Ctrl + D (Unix) or Ctrl + Z (Windows) to finish.
3
*/