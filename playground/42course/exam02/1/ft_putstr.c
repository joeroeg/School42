#include <unistd.h>

/*
// void ft_putstr(char *str) {
//     int i = 0;
//     while (str[i] != '\0') {
//         write(1, &str[i], 1);
//         i++;
//     }
// }

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write (1, "\n", 1);
}
*/

void ft_putstr(char *str)
{

}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        ft_putstr(argv[1]);
    }
    return 0;
}

