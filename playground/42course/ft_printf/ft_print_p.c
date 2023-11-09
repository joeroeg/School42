#include "ft_printf.h"

int ft_print_p(va_list *args)
{
	uintptr_t ptr_val = va_arg(*args, uintptr_t);
	char buffer[16] = {0};
	char *digits = "0123456789abcdef";
	int len = 0;
	int index = 0;

	if (ptr_val == 0) {
		write(1, "0x0", 3);
		return 3;
	}

	while (ptr_val != 0) {
		buffer[index++] = digits[ptr_val % 16];
		ptr_val /= 16;
	}

	write(1, "0x", 2);
	len += 2;

	while (index > 0) {
		write(1, &buffer[--index], 1);
		len++;
	}

	return len;
}
