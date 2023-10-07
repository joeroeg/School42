#include <stdio.h>

int main()
{
	char num;

	printf("F = Farenheit to Celsius / C = Celsius to Farenheit: \n");
	scanf("%c", &num);
	if (num == 'F'|| num == 'f')
	{
		printf("You choose transform Farenheit to Celsius \n");
	}
		
	else if (num == 'C' || num == 'c')
	{
		printf("You choose transform Celsius to Farenheit \n");
	}
	else
	{
		printf("You choose wrong input \n");
	}

	return (0);
}


