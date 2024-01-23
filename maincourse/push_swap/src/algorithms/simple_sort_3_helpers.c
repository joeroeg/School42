/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_3_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:46:19 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/22 19:53:20 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_sort_function	*create_jump_table(void)
{
	static t_sort_function	sort_jump_table[5];

	sort_jump_table[0] = sort_132;
	sort_jump_table[1] = sort_213;
	sort_jump_table[2] = sort_231;
	sort_jump_table[3] = sort_312;
	sort_jump_table[4] = sort_321;
	return (sort_jump_table);
}

int	get_sort_index(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first == 1 && second == 3 && third == 2)
		return (0);
	if (first == 2 && second == 1 && third == 3)
		return (1);
	if (first == 2 && second == 3 && third == 1)
		return (2);
	if (first == 3 && second == 1 && third == 2)
		return (3);
	if (first == 3 && second == 2 && third == 1)
		return (4);
	return (-1);
}
