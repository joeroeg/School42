/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:23:51 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/24 11:49:51 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	count_bits(int number)
{
	int	bits;

	bits = 0;
	while (number != 0)
	{
		bits++;
		number >>= 1;
	}
	return (bits);
}

static int	find_max_bits(t_node **stack)
{
	t_node	*current;
	int		max_index;

	if (!stack || !*stack)
		return (0);
	current = *stack;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (count_bits(max_index));
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = find_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(*stack_b) > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
