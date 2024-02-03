#include "config.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// uint32_t	set_color(int iter, t_fractol *frctl)
// {
// 	int			r = 0;
// 	int			g = 0;
// 	int			b = 0;
// 	double		t = 0;
// 	frctl->frctl_color = 1;

// 	t = (double)iter / MAX_ITERATIONS;
// 	if (frctl->frctl_color == 1)
// 	{
// 		r = (int)(9 * (1 - t) * pow(t, 3) * 255);
// 		g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
// 		b = (int)(8.5 * pow((1 - t), 3) * t * 255);
// 	}
// 	return (get_rgba(r, g, b, 255));
// }

// uint32_t set_color2(int iter) {
//     // double t = (double)iter / MAX_ITERATIONS;
//     int r, g, b;

//     // Adjust these parameters to change the frequency and phase of the color cycles
//     double frequency = 0.1; // Increase for more rapid color changes
//     double phase_r = 0; // Phase shift for red
//     double phase_g = 2; // Phase shift for green
//     double phase_b = 4; // Phase shift for blue

//     // Calculate color components using sine waves for a psychedelic effect
//     r = (int)((sin(frequency * iter + phase_r) * 127.5 + 127.5));
//     g = (int)((sin(frequency * iter + phase_g) * 127.5 + 127.5));
//     b = (int)((sin(frequency * iter + phase_b) * 127.5 + 127.5));

//     return get_rgba(r, g, b, 255); // Assuming get_rgba packs RGBA into uint32_t
// }

// uint32_t set_color(int iter) {
//     // Define your base and highlight colors in RGB
//     int base_r = 0, base_g = 0, base_b = 128; // Deep blue
//     int edge_r = 255, edge_g = 255, edge_b = 255; // White for the edge highlight

//     // Calculate the transition factor (t) based on the iteration count
//     double t = (double)iter / MAX_ITERATIONS;
//     t = pow(t, 0.9); // Use a power function to adjust the rate of color change

//     // Interpolate between the base color and the edge highlight color
//     int r = (int)((1 - t) * base_r + t * edge_r);
//     int g = (int)((1 - t) * base_g + t * edge_g);
//     int b = (int)((1 - t) * base_b + t * edge_b);

//     // Assuming get_rgba packs RGBA into uint32_t
//     return get_rgba(r, g, b, 255);
// }


// // Helper function to pack RGBA values into a uint32_t
// uint32_t get_rgba(int r, int g, int b, int a) {
//     return (a << 24) | (r << 16) | (g << 8) | b;
// }

// // Function to set color based on the iteration count
// uint32_t set_color(int iter) {
//     // Normalized iteration count
//     double t = (double)iter / MAX_ITERATIONS;

//     // Use sine and cosine functions to cycle through the colors
//     int r = (int)((sin(t * 2 * M_PI) + 1) * 127.5);
//     int g = (int)((sin(t * 2 * M_PI + 2 * M_PI / 3) + 1) * 127.5);
//     int b = (int)((sin(t * 2 * M_PI + 4 * M_PI / 3) + 1) * 127.5);

//     // Ensure values are within RGB range
//     r = r < 0 ? 0 : (r > 255 ? 255 : r);
//     g = g < 0 ? 0 : (g > 255 ? 255 : g);
//     b = b < 0 ? 0 : (b > 255 ? 255 : b);

//     // Return the color with full opacity
//     return get_rgba(r, g, b, 255);
// }

// uint32_t	set_color(int iter, t_fractol	*frctl)
// {
// 	int			r = 0;
// 	int			g = 0;
// 	int			b = 0;
// 	double		t = 0;
// 	frctl->frctl_color = 1;

// 	t = (double)iter / MAX_ITERATIONS;
// 	if (frctl->frctl_color == 1)
// 	{
// 		r = (int)(9 * (1 - t) * pow(t, 3) * 255);
// 		g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
// 		b = (int)(8.5 * pow((1 - t), 3) * t * 255);
// 	}
// 	if (frctl->frctl_color == 2)
// 	{
// 		b = (int)(9 * (1 - t) * pow(t, 3) * 255);
// 		g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
// 		r = (int)(8.5 * pow((1 - t), 3) * t * 255);
// 	}
// 	if (frctl->frctl_color == 3)
// 	{
// 		b = (int)(9 * (1 - t) * pow(t, 3) * 255);
// 		r = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
// 		g = (int)(8.5 * pow((1 - t), 3) * t * 255);
// 	}
// 	return (get_rgba(r, g, b, 255));
// }
