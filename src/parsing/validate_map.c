/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:36:44 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/10 20:03:53 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	flood(t_cub *data, int x, int y)
{
	bool	edge;
	char	original_char;

	if (is_boundary(data, x, y))
		return (true);
	if (data->map[x][y] != EMPTY && !((data->map[x][y] == 'N' || \
		data->map[x][y] == 'S' || \
		data->map[x][y] == 'E' || \
		data->map[x][y] == 'W') && data->map[x][y] == ' '))
		return (false);
	if (data->map[x][y] == WALL)
		return (false);
	original_char = data->map[x][y];
	data->map[x][y] = FILLED;
	edge = flood(data, x + 1, y) || \
		flood(data, x - 1, y) || \
		flood(data, x, y + 1) || \
		flood(data, x, y - 1);
	if (original_char == 'N' || original_char == 'S' || \
		original_char == 'E' || original_char == 'W')
		data->map[x][y] = original_char;
	return (edge);
}

void	restore_map_state(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '2')
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	check_player_enclosure(t_cub *data)
{
	bool	is_enclosed;

	is_enclosed = flood(data, data->player_x, data->player_y);
	if (is_enclosed)
		exit_error_message("Player start position is not properly enclosed.", \
			true);
	restore_map_state(data);
}

void	validate_map_playability(t_cub *data)
{
	int	i;

	i = 0;
	if (!validate_single_start_position(data))
		exit_error_message("Map must contain one player start position", true);
	if (!is_player_position_valid(data))
		exit_error_message("Player start position is invalid", true);
	while (i < data->map_height)
	{
		if (!is_line_valid(data->map[i]))
			exit_error_message("Error: Empty line or invalid character.", true);
		i++;
	}
	if (!find_player_position(data))
		exit_error_message("Player start position was not found.", true);
	check_player_enclosure(data);
}
