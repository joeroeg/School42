/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:48:26 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/06 20:12:52 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* REQUIREMENTS
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		ft_putchar(*str);
		str++;
		len++;
	}
	return (len);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_count_digits(long n)
{
    int count = 0;

    if (n == 0) {
        return 1; // Return 1 if the number is 0, as it has one digit
    }

    if (n < 0) {
        count = 1; // Start with 1 to account for the negative sign
        n = -n; // Make the number positive
    }

    while (n > 0) {
        n /= 10;
        ++count;
    }

    return count;
}

int ft_putnbr(int n) {
    unsigned int digit = 0;
    int len = 0;

	len = ft_count_digits(n);
    if (n < 0) {
        ft_putchar('-');
        digit = (unsigned int)-n;
    } else {
        digit = (unsigned int)n;
    }
    if (digit >= 10) {
        ft_putnbr(digit / 10);
    }
    ft_putchar((digit % 10) + '0');
    return len;
}

int ft_print_pointer(void *p) {
    int count = 0;
    uintptr_t ptr_val = (uintptr_t)p;
    char buffer[16];
    char *digits = "0123456789abcdef";

    // Initialize buffer with 0 to handle leading zeros
   for (int i = 0; i < 16; i++) {
        buffer[i] = '0';
    }

	if (p == 0)
	{
		ft_putstr("0x0");
		count += 3;
	}
	else
	{
    // Convert pointer to hex string from the end
    for (int i = 15; ptr_val > 0 && i >= 0; --i) {
        buffer[i] = digits[ptr_val % 16];
        ptr_val /= 16;
        count++;
    }

    // Print the '0x' prefix
    ft_putstr("0x");
    count += 2; // Add the two characters of "0x" to the count

    // Skip leading zeros and print the rest
    int start = 16 - count + 2;
    for (int i = start; i < 16; ++i) {
        ft_putchar(buffer[i]);
    }
	}
    return count;
}

int ft_print_small_hex(unsigned int num) {
	int len = 0;
    char *hexChars = "0123456789abcdef";
    if (num >= 16) {
        len += ft_print_small_hex(num / 16);
    }
    ft_putchar(hexChars[num % 16]);
	return (len + 1);
}

int ft_print_large_hex(unsigned int num) {
	int len = 0;
    char *hexChars = "0123456789ABCDEF";
    if (num >= 16) {
        len += ft_print_large_hex(num / 16);
    }
    ft_putchar(hexChars[num % 16]);
	return (len + 1);
}

unsigned int ft_putnbr_u(unsigned int n) {
    if (n >= 10) {
        ft_putnbr_u(n / 10);
    }
	ft_putchar((n % 10) + '0');
    return (ft_count_digits(n));
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int x = va_arg(args, int);
			len += ft_putnbr(x);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 's')
		{
			char *str = va_arg(args, char*);
			if (str == (char *)NULL)
			{
				len += ft_putstr("(null)");
			}
			else
			ft_putstr(str);
			len += ft_strlen(str);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'c')
		{
			int ch = va_arg(args, int);
			ft_putchar(ch);
			len ++;
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'p')
		{
			void *ptr = va_arg(args, void *);
			len += ft_print_pointer(ptr);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'x')
		{
			int x = va_arg(args, int);
			len += ft_print_small_hex(x);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'X')
		{
			int x = va_arg(args, int);
			len += ft_print_large_hex(x);
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar('%');
			len++;
			format += 2;
		}
		else if (*format == '%' && *(format + 1) == 'u')
		{
			unsigned int u = va_arg(args, unsigned int);
			len += ft_putnbr_u(u);
			format += 2;
		}
		else
		{
			ft_putchar(*format++);
			len++;
		}
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	char	input[] = "%X";
// 	int digit = -10;
// 	printf("(%d)", printf(input, digit));
// 	printf("\n");
// 	ft_printf("(%d)", ft_printf(input, digit));
// 	printf("\n");
// }
