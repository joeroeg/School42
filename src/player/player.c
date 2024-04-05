#include "cub3d.h"

void	load_player(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < MAX_MAP_WIDTH)
		{
			if (data->map[i][j] == 'N')
			{
				data->player.x = j + 0.5;
				data->player.y = i + 0.5;
				data->player.dir_x = 0;
				data->player.dir_y = -1;
				return ;
			}
			j++;
		}
		i++;
	}
	exit_error_message("Error: Player not found in map.", EXIT_FAILURE);
}
