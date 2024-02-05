#include "config.h"

void sierpinski(t_fractol *frctl) {
    // Define the vertices of the initial triangle and depth
    Point a = {100, 100}; // Example coordinates
    Point b = {500, 100};
    Point c = {300, 400};
    int depth = 5; // Example depth

    // Start the Sierpinski Triangle drawing process
	set_background_color(frctl, 0xFF);
    sierpinski_calc(a, b, c, frctl, depth);
}

void set_background_color(t_fractol *frctl, int color)
{
	int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            mlx_put_pixel(frctl->image, x, y, color); // Set each pixel to the background color
        }
    }
}


void draw_line(Point a, Point b, t_fractol *frctl)
{
	double dx = fabs(b.x - a.x), sx = a.x < b.x ? 1 : -1;
	double dy = -fabs(b.y - a.y), sy = a.y < b.y ? 1 : -1;
	double err = dx + dy, e2;
	while (true)
	{
		if (a.x >= 0 && a.x < WIDTH && a.y >= 0 && a.y < HEIGHT)
			mlx_put_pixel(frctl->image, a.x, a.y, 0xFFFF);
		if (fabs(a.x - b.x) < 1.0 && fabs(a.y - b.y) < 1.0)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			a.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			a.y += sy;
		}
	}
}

void draw_triangle(Point a, Point b, Point c, t_fractol *frctl)
{
	draw_line(a, b, frctl);
	draw_line(b, c, frctl);
	draw_line(c, a, frctl);
}

/**
 * Recursively calculate the Sierpinski Triangle
 * @brief
 * 1. draw the triangle
 * 2. split the triangle and recurse
 * 3. Recursively apply the algorithm to the three new triangles
 * @param a - Point a
 * @param b - Point b
 * @param c - Point c
 * @param depth - Depth of the recursion
 * @param frctl - Fractol struct
*/
void sierpinski_calc(Point a, Point b, Point c, t_fractol *frctl, int depth) {

    if (depth == 0) {
        // Base case: draw the triangle
        draw_triangle(a, b, c, frctl);
    } else {
        // Recursive case: split the triangle and recurse
        Point ab = {(a.x + b.x) / 2, (a.y + b.y) / 2}; // Midpoint of AB
        Point bc = {(b.x + c.x) / 2, (b.y + c.y) / 2}; // Midpoint of BC
        Point ca = {(c.x + a.x) / 2, (c.y + a.y) / 2}; // Midpoint of CA

        // Recursively apply the algorithm to the three new triangles
        sierpinski_calc(a, ab, ca, frctl, depth - 1);
        sierpinski_calc(ab, b, bc, frctl, depth - 1);
        sierpinski_calc(ca, bc, c, frctl, depth - 1);
    }
}
