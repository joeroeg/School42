#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

// size_t ft_putnbr(int n) {
//     unsigned int num;
//     size_t length = 1;

//     // Handle negative numbers
//     if (n < 0) {
//         ft_putchar('-');
//         num = (unsigned int)(-n);
//         length++; // Increase length for the '-' sign
//     } else {
//         num = (unsigned int)n;
//     }

//     // Print and count digits
//     if (num >= 10) {
//         length += ft_putnbr(num / 10); // Recursively print the rest of the number
// 		printf(" (%zu)\n", length);
//     }
//     length++; // Count the digit printed
//     ft_putchar((num % 10) + '0');
//     return length; // Return the total length of the number printed
// }

long	abss(int n)
{
	if (n == -2147483648)
		return (2147483648);
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_initialize(int n, int i)
{
	char	*tmp;

	if (n < 0)
	{
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		if (!tmp)
			return (0);
		tmp[0] = '-';
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		if (!tmp)
			return (0);
	}
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	*tmp;

	i = ft_count_digits(n);
	tmp = ft_initialize(n, i);
	if (!tmp)
		return (0);
	tmp[i] = '\0';
	num = abss(n);
	while (num > 9)
	{
		tmp[--i] = (num % 10) + '0';
		num /= 10;
	}
	tmp[--i] = (num % 10) + '0';
	return (tmp);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_d_i(int num)
{
	int		len;
	char	*str_num;

	len = 0;
	str_num = ft_itoa(num);
	len = ft_printstr(str_num);
	free(str_num);
	return (len);
}

int main()
{
	ft_print_d_i(-42);
}
