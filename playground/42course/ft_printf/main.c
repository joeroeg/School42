#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ft_printf.h"

int	main()
{
	char input[] = "%X";
	int digit = -42;
	printf("(%d)", printf(input, digit));
	printf("\n");
	ft_printf("(%d)", ft_printf(input, digit));
	printf("\n");
}
