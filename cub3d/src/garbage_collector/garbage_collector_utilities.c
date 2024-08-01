/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_utilities.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:34:12 by hezhukov          #+#    #+#             */
/*   Updated: 2024/04/11 13:18:31 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief garbage_collector serves as an access point to the system
 * @return Return the address of the head
 * @param head Static variable to keep track of the head of the linked list
*/
t_mblock	*garbage_collector(void)
{
	static t_mblock	head = {NULL, -1, NULL};

	return (&head);
}

void	clear_mlx(t_render *cmlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cmlx->textures[i])
			mlx_delete_texture(cmlx->textures[i]);
		i++;
	}
	if (cmlx->screen)
		mlx_delete_image(cmlx->mlx, cmlx->screen);
	if (cmlx->mlx)
		mlx_terminate(cmlx->mlx);
}

t_cub	*get_cub(void)
{
	static t_cub	cube;

	return (&cube);
}
