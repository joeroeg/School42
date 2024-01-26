#include "minilibx/mlx.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Tutorial Window");
	for (int y = HEIGHT * 0.1; y < HEIGHT - 0.9; y++)
	{
		for (int x = WIDTH * 0.1; x < WIDTH * 0.9; x++)
		{
			mlx_pixel_put(mlx, win, x, y, rand() % 0x1000000);
		}
		mlx_string_put(mlx, win, WIDTH * 0.12, HEIGHT * 0.12, 0xFF0000, "Joe Roeg");
	}
	mlx_loop(mlx);
}
