/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrepin <gcrepin@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:47:10 by gcrepin           #+#    #+#             */
/*   Updated: 2024/04/08 22:05:57 by gcrepin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define ROTATE_SPEED 0.0075
# define MOVE_SPEED 0.03

void	cub_rotate(t_cub *data);
bool	cub_check_collision(t_cub *data, double x, double y);
void	player_move(t_cub *data);

#endif
