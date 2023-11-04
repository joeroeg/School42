#include "ft_printf.h"

void my_function(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (; *format != '\0'; ++format) {
        if (*format == 'i') {
            int num = va_arg(args, int);
            printf("%d ", num);
        }
        else if (*format == 'c') {
            // note automatic conversion to integral type
            int ch = va_arg(args, int);
            printf("%c ", ch);
        }
    }

    va_end(args);
}

int main() {
    my_function("ici", 1, 'a', 2);
    return 0;
}
