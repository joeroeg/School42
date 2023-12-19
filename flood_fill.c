#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}


void flood_fill_util(char **tab, t_point size, int x, int y, char new_char, char old_char)
{
    // Base cases
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return;
    if (tab[y][x] != old_char)
        return;

    // Replace the character at (x, y)
    tab[y][x] = new_char;

    // Recur for north, east, south and west
    flood_fill_util(tab, size, x+1, y, new_char, old_char);
    flood_fill_util(tab, size, x-1, y, new_char, old_char);
    flood_fill_util(tab, size, x, y+1, new_char, old_char);
    flood_fill_util(tab, size, x, y-1, new_char, old_char);
}


void flood_fill(char **tab, t_point size, t_point begin)
{
    flood_fill_util(tab, size, begin.x, begin.y, 'F', tab[begin.y][begin.x]);
}


int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
