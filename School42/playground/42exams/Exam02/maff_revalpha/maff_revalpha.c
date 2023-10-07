#include <unistd.h>

int main() {
    char c = 'z';

    while (c >= 'a') {
        if (c % 2 == 0) {
            write(1, &c, 1);
        } else {
            char upper_c = c - ('a' - 'A');
            write(1, &upper_c, 1);
        }
        c--;
    }

    write(1, "\n", 1);
    return 0;
}
