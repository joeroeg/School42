#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct  s_point
{
    int x;
    int y;
}   t_point;

void flood_fill_u(char **tab, t_point size, int x, int y, char new, char old, bool **visited)
{
    printf("flood_fill_u: At x=%d, y=%d, old='%c', new='%c'\n", x, y, old, new); // Debug statement
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
    {
        printf("flood_fill_u: Out of bounds at x=%d, y=%d\n", x, y); // Debug statement
        return ;
    }
    if (tab[y][x] != old || visited[y][x])
    {
        printf("flood_fill_u: Cell at x=%d, y=%d is already visited or not target color (tab='%c', visited=%d)\n", x, y, tab[y][x], visited[y][x]); // Debug statement
        return ;
    }

    visited[y][x] = true;
    tab[y][x] = new;
    printf("flood_fill_u: Filling cell at x=%d, y=%d\n", x, y); // Debug statement

    flood_fill_u(tab, size, x + 1, y, new, old, visited);
    flood_fill_u(tab, size, x - 1, y, new, old, visited);
    flood_fill_u(tab, size, x, y + 1, new, old, visited);
    flood_fill_u(tab, size, x, y - 1, new, old, visited);
}



bool hasHoles(char **tab, t_point size) {
    printf("hasHoles: Allocating visited array...\n");
    bool **visited = malloc(size.y * sizeof(bool*));
    for (int i = 0; i < size.y; ++i) {
        visited[i] = malloc(size.x * sizeof(bool));
        memset(visited[i], false, size.x * sizeof(bool));
    }

    printf("hasHoles: Starting flood fill from the boundary...\n");
    // Perform flood fill from each cell on the boundary
    for (int i = 0; i < size.y; i++) {
        if (!visited[i][0] && tab[i][0] == '0') {
            printf("hasHoles: Flood filling from left boundary at (0, %d)\n", i);
            flood_fill_u(tab, size, 0, i, 'F', '0', visited);
        }
        if (!visited[i][size.x - 1] && tab[i][size.x - 1] == '0') {
            printf("hasHoles: Flood filling from right boundary at (%d, %d)\n", size.x - 1, i);
            flood_fill_u(tab, size, size.x - 1, i, 'F', '0', visited);
        }
    }
    for (int j = 0; j < size.x; j++) {
        if (!visited[0][j] && tab[0][j] == '0') {
            printf("hasHoles: Flood filling from top boundary at (%d, 0)\n", j);
            flood_fill_u(tab, size, j, 0, 'F', '0', visited);
        }
        if (!visited[size.y - 1][j] && tab[size.y - 1][j] == '0') {
            printf("hasHoles: Flood filling from bottom boundary at (%d, %d)\n", j, size.y - 1);
            flood_fill_u(tab, size, j, size.y - 1, 'F', '0', visited);
        }
    }

    printf("hasHoles: Checking for unvisited '0's...\n");
    bool hasHole = false;
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            if (!visited[i][j] && tab[i][j] == '0') {
                printf("hasHoles: Hole found at (%d, %d)\n", j, i);
                hasHole = true; // Map has holes
                break;
            }
        }
        if (hasHole) {
            break;
        }
    }

    // Free memory allocated for visited array
    printf("hasHoles: Freeing visited array...\n");
    for (int k = 0; k < size.y; ++k) {
        free(visited[k]);
    }
    free(visited);

    printf("hasHoles: Result - %s\n", hasHole ? "Map has holes" : "Map has no holes");
    return hasHole;
}



char **make_area(char** zone, t_point size)
{
    char **new;

    new = malloc(sizeof(char*) * size.y);
    for (int i = 0; i < size.y; ++i)
    {
        new[i] = malloc(size.x + 1);
        for (int j = 0; j < size.x; ++j)
		{
            new[i][j] = zone[i][j];
		}
        new[i][size.x] = '\0';
    }

    return new;
}

void flood_fill(char **tab, t_point size, t_point begin) {
	printf("flood_fill: Starting at x=%d, y=%d\n", begin.x, begin.y);
    char old_color = tab[begin.y][begin.x]; // Color of the starting point
    char new_color = 'F'; // New color to fill

    // Create a 2D array to keep track of visited cells
    bool **visited = malloc(size.y * sizeof(bool*));
    for (int i = 0; i < size.y; ++i) {
        visited[i] = malloc(size.x * sizeof(bool));
        memset(visited[i], false, size.x * sizeof(bool));
    }

    // Perform flood fill starting from the given point
    flood_fill_u(tab, size, begin.x, begin.y, new_color, old_color, visited);

    // Free memory allocated for visited array
    for (int i = 0; i < size.y; ++i) {
        free(visited[i]);
    }
	printf("flood_fill: Completed\n");
    free(visited);
}

int main(void)
{
    t_point size = {8, 5};
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11111111",
    };

    char **area = make_area(zone, size);
	printf("Original map:\n");
    for (int i = 0; i < size.y; ++i)
        printf("%s\n", area[i]);
    printf("\n");

    // Check for holes
    if (hasHoles(area, size)) {
        printf("The map has holes, it is not valid.\n");
    } else {
        printf("The map is valid, performing flood fill...\n");

        t_point begin = {7, 4};
		printf("Map after flood fill:\n");
        flood_fill(area, size, begin);
        for (int i = 0; i < size.y; ++i)
            printf("%s\n", area[i]);
    }
    return 0;
}
