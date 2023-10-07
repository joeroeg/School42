#include <stdio.h>

int main() {
    // Null character: \0 (ASCII value: 0)
    printf("This is a null character: %c\n", '\0');

    // Bell: \a (ASCII value: 7)
    printf("This is a bell sound: \aHello\n");

    // Backspace: \b (ASCII value: 8)
    printf("Back\b space\n");

    // Tab: \t (ASCII value: 9)
    printf("Hello\tworld!\n");

    // Newline: \n (ASCII value: 10)
    printf("Line 1\nLine 2\n");

    // Vertical tab: \v (ASCII value: 11)
    printf("Vertical\vtab\n");

    // Form feed: \f (ASCII value: 12)
    printf("Form\ffeed\n");

    // Carriage return: \r (ASCII value: 13)
    printf("Carriage\r return\n");

    // Escape: \e (ASCII value: 27)
    printf("Escape\e sequence\n");

    // Delete: \177 (ASCII value: 127)
    printf("Delete: %c\n", 127);

    return 0;
}
