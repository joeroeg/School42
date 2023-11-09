#include "ft_printf.h"

int ft_print_c(va_list *args)
{
	char c = (char)va_arg(*args, int);
	write (1, &c, 1);
	return (1);
}
