/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:05:26 by kyung-ki          #+#    #+#             */
/*   Updated: 2024/01/19 21:17:46 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_helper_a(t_node **deque_a, t_node **deque_b)
{
	if ((*deque_a)->val < (*deque_a)->next->next->val)
		ft_do_instruction(deque_a, NULL, "sa", 0);
	else if ((*deque_a)->next->val > (*deque_a)->next->next->val)
	{
		ft_do_instruction(deque_a, deque_b, "ra", 0);
		ft_do_instruction(deque_a, NULL, "sa", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pb", 2);
		ft_do_instruction(deque_a, deque_b, "rra", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
	}
	else
	{
		ft_do_instruction(deque_a, NULL, "ra", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pb", 2);
		ft_do_instruction(deque_a, deque_b, "rra", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
	}
}

void	ft_helper_a2(t_node **deque_a, t_node **deque_b)
{
	if ((*deque_a)->val > (*deque_a)->next->next->val)
	{
		ft_do_multi_instruction(deque_a, deque_b, "ra", 2);
		ft_do_instruction(deque_a, deque_b, "pb", 0);
		ft_do_multi_instruction(deque_a, deque_b, "rra", 2);
		ft_do_instruction(deque_a, deque_b, "pa", 0);
	}
	else if ((*deque_a)->next->val > (*deque_a)->next->next->val)
	{
		ft_do_instruction(deque_a, deque_b, "pb", 0);
		ft_do_instruction(deque_a, NULL, "sa", 0);
		ft_do_instruction(deque_a, deque_b, "pa", 0);
	}
}

void	ft_helper_b(t_node **deque_a, t_node **deque_b)
{
	if ((*deque_b)->next->val < (*deque_b)->next->next->val)
	{
		ft_do_multi_instruction(deque_a, deque_b, "rb", 2);
		ft_do_instruction(deque_a, deque_b, "pa", 0);
		ft_do_instruction(deque_a, deque_b, "rrb", 0);
		ft_do_instruction(deque_a, deque_b, "pa", 0);
		ft_do_instruction(deque_a, deque_b, "rrb", 0);
		ft_do_instruction(deque_a, deque_b, "pa", 0);
	}
	else if ((*deque_b)->val < (*deque_b)->next->next->val)
	{
		ft_do_instruction(deque_a, deque_b, "rb", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
		ft_do_instruction(deque_a, deque_b, "rrb", 0);
		ft_do_instruction(deque_a, deque_b, "pa", 0);
	}
	else if ((*deque_b)->val > (*deque_b)->next->next->val)
	{
		ft_do_instruction(deque_a, deque_b, "sb", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 3);
	}
}

void	ft_helper_b2(t_node **deque_a, t_node **deque_b)
{
	if ((*deque_b)->val < (*deque_b)->next->next->val)
	{
		ft_do_multi_instruction(deque_a, deque_b, "rb", 2);
		ft_do_instruction(deque_a, deque_b, "pa", 0);
		ft_do_multi_instruction(deque_a, deque_b, "rrb", 2);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
	}
	else if ((*deque_b)->next->val < (*deque_b)->next->next->val)
	{
		ft_do_instruction(deque_a, deque_b, "pa", 0);
		ft_do_instruction(deque_a, deque_b, "sb", 0);
		ft_do_multi_instruction(deque_a, deque_b, "pa", 2);
	}
	else
		ft_do_multi_instruction(deque_a, deque_b, "pa", 3);
}
