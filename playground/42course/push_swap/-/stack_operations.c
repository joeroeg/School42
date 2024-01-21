/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:13:39 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/20 18:47:46 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap(t_node **stack)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (-1);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
	return (0);
}

int	ft_push(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return (-1);
	tmp = (*stack_from)->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	(*stack_from)->next = *stack_to;
	if (*stack_to != NULL)
		(*stack_to)->prev = *stack_from;
	*stack_to = *stack_from;
	*stack_from = tmp;
	return (0);
}

int	ft_rotate(t_node **stack, int reverse)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (-1);
	tmp = *stack;
	if (reverse == 0)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = ft_last_node(*stack);
		ft_last_node(*stack)->next = tmp;
	}
	else
	{
		*stack = ft_last_node(*stack);
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->next = tmp;
		tmp->prev = *stack;
	}
	return (0);
}

int	ft_do_instruction(t_node **stack_a, t_node **stack_b,
	char *operation, int is_print)
{
	if (!is_print)
		printf("%s\n", operation);
	if (strcmp(operation, "sa") == 0)
		return (ft_swap(stack_a));
	else if (strcmp(operation, "sb") == 0)
		return (ft_swap(stack_b));
	else if (strcmp(operation, "ss") == 0)
		return (ft_swap(stack_a) && ft_swap(stack_b));
	else if (strcmp(operation, "pa") == 0)
		return (ft_push(stack_b, stack_a));
	else if (strcmp(operation, "pb") == 0)
		return (ft_push(stack_a, stack_b));
	else if (strcmp(operation, "ra") == 0)
		return (ft_rotate(stack_a, 0));
	else if (strcmp(operation, "rb") == 0)
		return (ft_rotate(stack_b, 0));
	else if (strcmp(operation, "rr") == 0)
		return (ft_rotate(stack_a, 0) && ft_rotate(stack_b, 0));
	else if (strcmp(operation, "rra") == 0)
		return (ft_rotate(stack_a, 1));
	else if (strcmp(operation, "rrb") == 0)
		return (ft_rotate(stack_b, 1));
	else if (strcmp(operation, "rrr") == 0)
		return (ft_rotate(stack_a, 1) && ft_rotate(stack_b, 1));
	return (-1);
}

int	ft_do_multi_instruction(t_node **stack_a, t_node **stack_b,
	char *operation, int num)
{
	while (num--)
	{
		if (ft_do_instruction(stack_a, stack_b, operation, 0) == -1)
			return (-1);
	}
	return (0);
}
