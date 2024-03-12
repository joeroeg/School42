#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while(*str)
		len += write(1, str++, 1);
}

int ft_putnbr(long long int num, int base, int *len)
{
	char *hex = "0123456789abcdef";

	if (num < 0)
	{
		num *= -1;
		len += write(1, "-", 1);
	}
	if (num >= base)
		ft_putnbr((num / base), base, len);
	len += write(1, &hex[num % base], 1);
}

int ft_printf(char *format, ...)
{
	int len = 0;
	va_list pointer;
	va_start (pointer, format);

	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				ft_putstr((va_arg(pointer, char *)), &len);
			else if (*format == 'd')
				ft_putnbr(((long long int)va_arg(pointer, int)), 10, &len);
			else if (*format == 'x')
				ft_putnbr(((long long int)va_arg(pointer, unsigned int)), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(pointer);
}

int main()
{
	char	*str = "hello";
	int		num = 16;

	printf("%s\n", str);
	printf("world\n");
	printf("%d\n", num);
	printf("%x\n", num);
	printf("%x\n", INT_MIN);
	printf("%x\n", INT_MAX);

	printf("\n");

	ft_printf("%s\n", str);
	ft_printf("world\n");
	ft_printf("%d\n", num);
	ft_printf("%x\n", num);
	ft_printf("%x\n", INT_MIN);
	ft_printf("%x\n", INT_MAX);
}
