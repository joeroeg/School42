#include "cub3d.h"

void	load_player(t_cub *data)
{
	data->player.x = data->player_y + 0.5;
	data->player.y = data->player_x + 0.5;
	data->player.dir_x = (data->player_direction == 'E')
			- (data->player_direction == 'W');
	data->player.dir_y = (data->player_direction == 'S')
			- (data->player_direction == 'N');
}
