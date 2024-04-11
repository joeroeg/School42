/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:41:01 by gcrepin           #+#    #+#             */
/*   Updated: 2024/04/10 16:00:12 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

static double	find_intersection(t_cub *data, double ray_x, double ray_y)
{
	double	x;
	double	y;

	x = ((ray_y - (ray_x * data->player.dir_y / data->player.dir_x))
			- (data->player.y
				+ (data->player.x * data->player.dir_x / data->player.dir_y)))
		/ ((-data->player.dir_x / data->player.dir_y)
			- (data->player.dir_y / data->player.dir_x));
	y = x * (-data->player.dir_x / data->player.dir_y)
		+ (data->player.y
			+ (data->player.x * data->player.dir_x / data->player.dir_y));
	return (pythagorean(x - ray_x, y - ray_y));
}

static double	get_slope(t_cub *data, t_vector *dir)
{
	double	x;
	double	y;

	x = data->player.x - (data->player.dir_y
			* ((double) VIEW_PLANE_SIZE * 2 / WINDOW_WIDTH) * data->render.i)
		+ data->player.dir_x * VIEW_PLANE_DISTANCE;
	y = data->player.y + (data->player.dir_x
			* ((double) VIEW_PLANE_SIZE * 2 / WINDOW_WIDTH) * data->render.i)
		+ data->player.dir_y * VIEW_PLANE_DISTANCE;
	dir->x = ((x - data->player.x) > 0) - ((x - data->player.x) < 0);
	dir->y = ((y - data->player.y) > 0) - ((y - data->player.y) < 0);
	return ((data->player.y - y) / (data->player.x - x));
}

static void	draw(t_cub *data, t_vector x_ray, t_vector y_ray, t_vector dir)
{
	if (pythagorean(x_ray.x - data->player.x, x_ray.y - data->player.y)
		< pythagorean(y_ray.x - data->player.x, y_ray.y - data->player.y))
		draw_column(data, find_intersection(data, x_ray.x, x_ray.y),
			data->render.i + WINDOW_WIDTH / 2,
			dir.x < 0 ? WEST : EAST, x_ray.y - (int) x_ray.y);
	else
		draw_column(data, find_intersection(data, y_ray.x, y_ray.y),
			data->render.i + WINDOW_WIDTH / 2,
			dir.y < 0 ? NORTH : SOUTH, y_ray.x - (int) y_ray.x);
}

static double	innit_rays(t_cub *data, t_vector *x_ray, t_vector *y_ray,
			t_vector *dir)
{
	double	slope;

	slope = get_slope(data, dir);
	x_ray->x = (int)(data->player.x + (dir->x > 0));
	x_ray->y = data->player.y + (x_ray->x - data->player.x) * slope;
	y_ray->y = (int) data->player.y + (dir->y > 0);
	y_ray->x = data->player.x + (y_ray->y - data->player.y) / slope;
	return (slope);
}

void	draw_rays(t_cub *data)
{
	double		slope;
	t_vector	x_ray;
	t_vector	y_ray;
	t_vector	dir;

	data->render.i = (int)(-floor((double) WINDOW_WIDTH / 2));
	while (data->render.i < (int) ceil((double) WINDOW_WIDTH / 2))
	{
		slope = innit_rays(data, &x_ray, &y_ray, &dir);
		while (((int) x_ray.x >= 0 && (int) x_ray.x < MAX_MAP_WIDTH
				&& (int) x_ray.y >= 0
				&& (int) x_ray.y < MAX_MAP_HEIGHT)
			&& data->map[(int) x_ray.y][(int) x_ray.x - (dir.x < 0)] != '1')
		{
			x_ray.x += dir.x;
			x_ray.y += dir.x * slope;
		}
		while ((int) y_ray.x >= 0 && (int) y_ray.x < MAX_MAP_WIDTH
			&& (int) y_ray.y >= 0
			&& (int) y_ray.y < MAX_MAP_HEIGHT
			&& (data->map[(int) y_ray.y - (dir.y < 0)][(int) y_ray.x] != '1'))
		{
			y_ray.x += dir.y / slope;
			y_ray.y += dir.y;
		}
		draw(data, x_ray, y_ray, dir);
		data->render.i++;
	}
}
