/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:23:46 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/23 12:34:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * @brief find a minimum value in a stack
 * @param stack stack to search in
 * @param val value to exclude from search
*/
int	find_minimum(t_node **stack, int exclude_value)
{
	t_node	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != exclude_value)
			min = head->index;
	}
	return (min);
}

/**
 * @brief find a position of a value in a stack
 * @return position of a value in a stack
 * @return -1 if value not found
*/
int	find_position(t_node **stack, int value)
{
	int		position;
	t_node	*head;

	head = *stack;
	position = 0;
	while (head != NULL)
	{
		if (head->index == value)
		{
			return (position);
		}
		head = head->next;
		position++;
	}
	return (-1);
}

void	sort_3(t_node **stack_a)
{
	t_sort_function	*jump_table;
	int				index;

	jump_table = create_jump_table();
	index = get_sort_index(stack_a);
	if (index != -1)
		jump_table[index](stack_a);
}

void	simple_sort(t_node **stack_a, t_node **stack_b, int limit)
{
	push_n_minimum_to_b(stack_a, stack_b, limit);
	reset_indices(stack_a);
	index_stack(stack_a);
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
