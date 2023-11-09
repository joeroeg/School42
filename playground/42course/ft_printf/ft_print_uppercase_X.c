#include "ft_printf.h"

int ft_print_uppercase_X(va_list *args)
{
	unsigned int num = va_arg(*args, unsigned int);
	char buffer[16] = {0};
	char *hex_chars = "0123456789ABCDEF";
	int len = 0;
	int index = 0;


    if (num == 0)
    {
        write(1, "0", 1);
        return 1;
    }

	while (num != 0) {
		buffer[index++] = hex_chars[num % 16];
		num /= 16;
	}

	while (index > 0) {
		write(1, &buffer[--index], 1);
		len++;
	}

	return len;
}
