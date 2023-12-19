#include "flood_fill.h"

void flood_fill_u(char **tab, t_point size, int x, int y, char new, char old)
{
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return ;
    if (tab[y][x] != old)
        return ;
    tab[y][x] = new;

    flood_fill_u(tab, size, x + 1, y, new, old);
    flood_fill_u(tab, size, x - 1, y, new, old);
    flood_fill_u(tab, size, x, y + 1, new, old);
    flood_fill_u(tab, size, x, y - 1, new, old);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    flood_fill_u(tab, size, begin.x, begin.y, 'F', tab[begin.y][begin.x]);
}


