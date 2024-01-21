/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:23:28 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/20 18:38:27 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three_a(t_node **stack_a)
{
	if ((*stack_a)->val > (*stack_a)->next->val)
	{
		if ((*stack_a)->val < (*stack_a)->next->next->val)
			ft_do_instruction(stack_a, NULL, "sa", 0);
		else if ((*stack_a)->next->val > (*stack_a)->next->next->val)
		{
			ft_do_instruction(stack_a, NULL, "sa", 0);
			ft_do_instruction(stack_a, NULL, "rra", 0);
		}
		else
			ft_do_instruction(stack_a, NULL, "ra", 0);
	}
	else if ((*stack_a)->val < (*stack_a)->next->val)
	{
		if ((*stack_a)->val > (*stack_a)->next->next->val)
			ft_do_instruction(stack_a, NULL, "rra", 0);
		else if ((*stack_a)->next->val > (*stack_a)->next->next->val)
		{
			ft_do_instruction(stack_a, NULL, "sa", 0);
			ft_do_instruction(stack_a, NULL, "ra", 0);
		}
	}
}

void	push_swap(t_node *stack_a, t_node *stack_b, int len)
{
	if (ft_lst_is_sorted(stack_a, 0))
		return ;
	if (len == 2)
		ft_do_instruction(&stack_a, &stack_b, "sa", 0);
	else if (len == 3)
		ft_sort_three_a(&stack_a);
	else
		if (ft_quicksort_a(&stack_a, &stack_b, len) == 0)
			exit(EXIT_FAILURE);
	ft_lst_clear(stack_a);
	ft_lst_clear(stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (argc > 1)
	{
		while (argv[++i])
		{
			if (ft_argu_check(stack_a, argv[i]) == 0)
				ft_free_stop(stack_a, ERROR_MSG_INPUT);
			stack_a = ft_lst_add_top_front(stack_a, ft_atoi(argv[i]));
		}
		push_swap(stack_a, stack_b, ft_lst_size(stack_a));
	}
	return (0);
}
