/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:37:31 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/10 20:03:47 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_player_position_valid(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
			data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				if (i == 0 || i == data->map_height - 1 || j == 0 || \
				j == (int)ft_strlen(data->map[i]) - 1 || \
				data->map[i - 1][j] == ' ' || \
				data->map[i + 1][j] == ' ' || data->map[i][j - 1] == ' ' ||
				data->map[i][j + 1] == ' ')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	validate_single_start_position(t_cub *data)
{
	int		start_positions;
	int		i;
	char	*line;

	start_positions = 0;
	i = 0;
	while (i < data->map_height)
	{
		line = data->map[i];
		while (*line == ' ')
			line++;
		while (*line)
		{
			if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
			{
				start_positions++;
				if (start_positions > 1)
					return (false);
			}
			line++;
		}
		i++;
	}
	return (start_positions == 1);
}

bool	find_player_position(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
			data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player_x = i;
				data->player_y = j;
				data->player_direction = data->map[i][j];
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_boundary(t_cub *data, int x, int y)
{
	return (x < 0 || \
			x >= data->map_height || \
			y < 0 || y >= data->map_width || \
			y >= (int) ft_strlen(data->map[x]) || \
			data->map[x][y] == ' ');
}
