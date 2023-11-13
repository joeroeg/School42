#include <unistd.h>

int main() {
    char digit = '9';
    while (digit >= '0') {
        write(1, &digit, 1);
        digit--;
    }
    write(1, "\n", 1);
    return 0;
}
