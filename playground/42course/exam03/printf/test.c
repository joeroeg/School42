#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int ft_putstr(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (*len);
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
	return *len;
}

/*
	I forgot:
	how to print only text printf("world")


*/
int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list ptr;
	va_start(ptr, format);

	while(*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(ptr, char *), &len);
			if (*format == 'd')
				ft_putnbr((long long int)va_arg(ptr, int), 10, &len);
			if (*format == 'x')
				ft_putnbr((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return len;
}

int main()
{
	char *str = "hello";
	int num = INT_MAX;

	printf("%s\n", str);
	printf("world\n");
	printf("%d\n", num);
	printf("%x\n", num);

	printf("\n");

	ft_printf("%s\n", str);
	ft_printf("world\n");
	ft_printf("%d\n", num);
	ft_printf("%x\n", num);
}
