#include <stdio.h>

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	if (a == 0 && b == 0) return 0;
	return (a * b / gcd(a, b));
}
