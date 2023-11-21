#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
int	letter_count(char c)
{
	int	repeat;

	if (c > 'A' && c <= 'Z')
		repeat = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		repeat = c - 'a' + 1;
	else
		repeat = 1;
	return (repeat);
}


void repeat_alpha(char *str)
{
	int	repeat;

	while (*str)
	{
		repeat = letter_count(*str);
		while (repeat--)
			write(1, str, 1);
		str++;
	}
}


int main(int ac, char **av)
{
    if (ac == 2)
        repeat_alpha(av[1]);

    write(1, "\n", 1);
    return (0);
}
*/

int main(int ac, char **av)
{

}
