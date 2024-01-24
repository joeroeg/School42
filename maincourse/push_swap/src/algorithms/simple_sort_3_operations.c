/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_3_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:52:14 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/23 21:19:03 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_132(t_node **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

void	sort_213(t_node **stack_a)
{
	sa(stack_a);
}

void	sort_231(t_node **stack_a)
{
	rra(stack_a);
}

void	sort_312(t_node **stack_a)
{
	ra(stack_a);
}

void	sort_321(t_node **stack_a)
{
	sa(stack_a);
	rra(stack_a);
}
