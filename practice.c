#include <stdio.h>
#include <unistd.h>

int ft_count_digits(int n)
{
	int len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void ft_putchar(int c)
{
	write(1, &c, 1);
}


unsigned int ft_putnbr_u(unsigned int n) {
    unsigned int len = 0;

	len = ft_count_digits(n);
    if (n >= 10) {
        ft_putnbr_u(n / 10);
    }
    ft_putchar((n % 10) + '0');
    return len;
}

int main()
{
	printf("(%d)", ft_putnbr_u(1000));
}
