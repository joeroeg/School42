/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:50:40 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/20 18:53:45 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	ft_less_three_a(t_node **stack_a, t_node **stack_b, int len)
// {
// 	if (len == 2)
// 	{
// 		if ((*stack_a)->val > (*stack_a)->next->val)
// 			ft_do_instruction(stack_a, stack_b, "sa", 0);
// 	}
// 	else if (len == 3)
// 	{
// 		if ((*stack_a)->val > (*stack_a)->next->val)
// 			ft_helper_a(stack_a, stack_b);
// 		else if ((*stack_a)->val < (*stack_a)->next->val)
// 			ft_helper_a2(stack_a, stack_b);
// 	}
// 	return (1);
// }

// int	ft_less_three_b(t_node **stack_a, t_node **stack_b, int len)
// {
// 	if (len == 2)
// 	{
// 		if ((*stack_b)->val < (*stack_b)->next->val)
// 		{
// 			ft_do_instruction(stack_a, stack_b, "sb", 0);
// 			ft_do_multi_instruction(stack_a, stack_b, "pa", 2);
// 		}
// 		else
// 			ft_do_multi_instruction(stack_a, stack_b, "pa", 2);
// 	}
// 	else if (len == 3)
// 	{
// 		if ((*stack_b)->val < (*stack_b)->next->val)
// 			ft_helper_b(stack_a, stack_b);
// 		else
// 			ft_helper_b2(stack_a, stack_b);
// 	}
// 	return (1);
// }

int	ft_quicksort_a(t_node **stack_a, t_node **stack_b, int len)
{
	int	pivot;
	int	num;
	int	pushed_under;

	if (ft_lst_is_sorted(*stack_a, ASCENDING))
		return (1);
	num = len;
	// if (len <= 3)
	// 	return (ft_less_three_a(stack_a, stack_b, len));
	pushed_under = 0;
	if (!get_pivot(&pivot, *stack_a, len))
		return (0);
	while (len != num / 2 + num % 2)
	{
		if ((*stack_a)->val < pivot && (len--))
			ft_do_instruction(stack_a, stack_b, "pb", 0);
		else if ((++pushed_under))
			ft_do_instruction(stack_a, stack_b, "ra", 0);
	}
	while (!ft_lst_is_sorted(*stack_a, ASCENDING) && pushed_under--)
		ft_do_instruction(stack_a, stack_b, "rra", 0);
	return (ft_quicksort_a(stack_a, stack_b, num / 2 + num % 2)
		&& ft_quicksort_b(stack_a, stack_b, num / 2));
}

int	ft_quicksort_b(t_node **stack_a, t_node **stack_b, int len)
{
	int	pivot;
	int	num;
	int	pushed_under;

	pushed_under = 0;
	if (ft_lst_is_sorted(*stack_b, DESCENDING))
		while (len--)
			ft_do_instruction(stack_a, stack_b, "pa", 0);
	// if (len <= 3)
	// 	return (ft_less_three_b(stack_a, stack_b, len));
	num = len;
	if (!get_pivot(&pivot, *stack_b, len))
		return (0);
	while (len != num / 2)
	{
		if ((*stack_b)->val >= pivot && len--)
			ft_do_instruction(stack_a, stack_b, "pa", 0);
		else if (++pushed_under)
			ft_do_instruction(stack_a, stack_b, "rb", 0);
	}
	while (!ft_lst_is_sorted(*stack_b, DESCENDING) && pushed_under--)
		ft_do_instruction(stack_a, stack_b, "rrb", 0);
	return (ft_quicksort_a(stack_a, stack_b, num / 2 + num % 2)
		&& ft_quicksort_b(stack_a, stack_b, num / 2));
}

int	get_pivot(int *pivot, t_node *deque, int len)
{
	int		*cache;
	int		*buf;
	int		i;
	t_node	*tmp;

	tmp = deque;
	cache = (int *)malloc(sizeof(int) * len);
	if (!cache)
		return (0);
	buf = (int *)calloc(len, sizeof(int)); // calloc is forbidden calloc() gives you a zero-initialized buffer, while malloc() leaves the memory uninitialized.
	if (!buf)
		return (0);
	i = -1;
	while (++i < len)
	{
		cache[i] = tmp->val;
		tmp = tmp->next;
	}
	ft_mergesort(0, len - 1, cache, buf);
	*pivot = cache[len / 2];
	free(cache);
	free(buf);
	return (1);
}
