#ifndef RENDER_H
# define RENDER_H

#define VIEW_PLANE_SIZE 0.66
#define VIEW_PLANE_DISTANCE 1

void cub_key_hook(mlx_key_data_t key_data, void *param);
void draw_rays(t_cub *data);
void draw_column(t_cub *data, double distance, int x, t_direction direction,
		double trail);
double pythagorean(double a, double b);

typedef struct s_vector
{
	double x;
	double y;
} t_vector;

#endif
