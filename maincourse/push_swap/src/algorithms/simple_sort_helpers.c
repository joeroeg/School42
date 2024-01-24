/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:45:33 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/23 21:19:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reset_indices(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head)
	{
		head->index = -1;
		head = head->next;
	}
}

int	find_next_minimum(t_node **stack, int first_min)
{
	return (find_minimum(stack, first_min));
}

void	push_n_minimum_to_b(t_node **stack_a, t_node **stack_b, int n)
{
	int	min;
	int	min_position;
	int	stack_size;

	min = find_minimum(stack_a, -1);
	while (n > 0)
	{
		min_position = find_position(stack_a, min);
		stack_size = ft_lstsize(*stack_a);
		move_minimum_to_top(stack_a, min_position, stack_size);
		pb(stack_a, stack_b);
		min = find_next_minimum(stack_a, min);
		n--;
	}
}

void	push_minimum_to_b(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	min_position;
	int	stack_size;

	min = find_minimum(stack_a, -1);
	min_position = find_position(stack_a, min);
	stack_size = ft_lstsize(*stack_a);
	move_minimum_to_top(stack_a, min_position, stack_size);
	pb(stack_a, stack_b);
}

void	move_minimum_to_top(t_node **stack_a, int min_position, int stack_size)
{
	int	i;

	if (min_position <= stack_size / 2)
	{
		i = 0;
		while (i < min_position)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (stack_size - min_position))
		{
			rra(stack_a);
			i++;
		}
	}
}
