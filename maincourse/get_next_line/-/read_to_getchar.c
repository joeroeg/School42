#include <stdio.h>

/* getchar: unbuffered single character input */
int ft_getchar(void)
{
	char c;
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


int main()
{
	char c;
	while ((c = ft_getchar()) != EOF)
	{
		putchar(c);
	}
	return 0;
}
