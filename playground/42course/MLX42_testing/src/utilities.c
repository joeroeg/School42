#include "config.h"

void	print_help(void)
{
	printf("Usage: ./fractol [fractal_set_nb]\n\n");
	printf("Available Sets\n\n");
	printf("   --> 1️⃣  Mandelbrot\n");
	printf("   --> 2️⃣  Julia\n");
	printf("   --> 3️⃣  Burningship\n\n");
	printf("    |-> For Julia, please provide 2 arguments:\n");
	printf("    |-> ./fractol 2 [A] [B]\n\n");
	printf("    |-> Few examples that you could try\n");
	printf("    |-> ./fractol 2 -0.8 0.156\n");
	printf("    |-> ./fractol 2 0.285 0.01\n");
	exit(EXIT_SUCCESS);
}
