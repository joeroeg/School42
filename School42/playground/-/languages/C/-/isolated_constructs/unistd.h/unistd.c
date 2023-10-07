#include	<unistd.h>

int	main(void)
{
	unsigned char	c;

	c = 0;

	while (c < 150)
	{
		write(1, &c, 1);
		c++;
	}
}