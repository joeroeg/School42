#ifndef PLAYER_H
# define PLAYER_H

# define ROTATE_SPEED 0.0075
# define MOVE_SPEED 0.03

void cub_rotate(t_cub *data);
bool cub_check_collision(t_cub *data, double x, double y);
void player_move(t_cub *data);

#endif
