#include <stdio.h>

void printAddresses(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        printf("Address of character '%c': %p\n", s[i], (void *)&s[i]);
    }
}

int main() {
    const char *text = "Hello, World!";
    printAddresses(text);
    return 0;
}
