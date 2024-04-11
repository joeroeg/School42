/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:35:32 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/11 10:59:45 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_reset_line(char **line)
{
	if (line != NULL && *line != NULL)
	{
		gc_free(*line);
		*line = NULL;
	}
}

int	is_line_empty_or_whitespace(const char *line)
{
	int	i;

	if (line == NULL)
		return (1);
	i = 0;
	while (line[i] != '\0')
	{
		if (!isspace((unsigned char)line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	initialize_map_parsing(t_cub *data, \
	int *line_number, int *map_found, int *found_spaces)
{
	(void)data;
	*line_number = 0;
	*map_found = 0;
	*found_spaces = 0;
}

void	finalize_map_parsing(t_cub *data, int line_number)
{
	data->map_height = line_number;
	if (line_number > 0)
		data->map_width = (int) ft_strlen(data->map[0]);
	validate_map_playability(data);
}

bool	is_line_valid(const char *line)
{
	bool	valid_characters_only;
	int		i;

	valid_characters_only = true;
	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || \
		line[i] == 'S' || line[i] == 'E' || line[i] == 'W' || line[i] == ' '))
		{
			valid_characters_only = false;
			break ;
		}
		i++;
	}
	return (valid_characters_only);
}
