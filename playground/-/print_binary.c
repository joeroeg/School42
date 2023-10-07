#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void print_binary(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        char bit = (num & (1 << i)) ? '1' : '0';
        ft_putchar(bit);
        if (i % 4 == 0)
            ft_putchar(' '); // Add a space every 4 bits for readability
    }
}

void ft_putnbr(int nb) {
    unsigned int nbr;

    if (nb < 0) {
        nbr = -nb;
        write(1, "-", 1);
    } else {
        nbr = nb;
    }

    if (nb / 10 != 0)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + '0');
}

int main() {

    for (int i = INT_MIN; i >=INT_MIN; i++)
    {
        ft_putnbr(i);
        write(1, "\n", 1);
        // write(1, "Binary representation: ", 23);
        print_binary(i);
        write(1, "\n", 1);
    }
    // int num = INT_MAX;
    // ft_putnbr(num);
    // write(1, "\n", 1);
    // write(1, "Binary representation: ", 23);
    // print_binary(num);
    // write(1, "\n", 1);

    // int negative_num = INT_MIN;
    // ft_putnbr(negative_num);
    // write(1, "\n", 1);
    // write(1, "Binary representation: ", 23);
    // print_binary((unsigned int)negative_num);
    // write(1, "\n", 1);

    return 0;
}
