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
				j == (int)strlen(data->map[i]) - 1 || \
				data->map[i - 1][j] == ' ' || \
				data->map[i + 1][j] == ' ' || data->map[i][j-1] == ' ' ||
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

void	printMapWithCoordinates(t_cub *data)
{
	printf("\n");
	printf("   ");
    for (int j = 0; j < data->map_width; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < data->map_height; i++) {
        // Print row number
        printf("%d: ", i);
        for (int j = 0; j < data->map_width; j++) {
            printf("%c ", data->map[i][j]);
        }
        printf("\n");
    }
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
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
