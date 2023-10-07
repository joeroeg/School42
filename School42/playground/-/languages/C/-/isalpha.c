//%cflags:-lm

#include <stdio.h>

int	isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	main(void)

{
	char	c;
	c = 'a';
	printf("%d", isalpha(c));
	return (0);
}

