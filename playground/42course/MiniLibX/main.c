#include "minilibx/mlx.h"

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 800, 600, "Tutorial Window");
	mlx_pixel_put(mlx, win, 250, 0xff0000, 0xff0000);
	mlx_loop(mlx);
}
