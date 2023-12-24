#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int main() {
    int array[] = {3, 1, 4};
    unsigned int size = sizeof(array) / sizeof(array[0]);
    sort_int_tab(array, size);
    for (unsigned int i = 0; i < size; i++) {
    printf("[%d]", array[i]);
    }
    return 0;
}
