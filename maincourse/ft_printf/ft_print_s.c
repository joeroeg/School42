#include "ft_printf.h"

int ft_print_s(va_list *args)
{
	const char *s = va_arg(*args, const char *);
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (*s) {
		write(1, s++, 1);
		len++;
	}
	return (len);
}
