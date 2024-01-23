/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:41:30 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/23 11:28:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	error_message_free(char ***args, char *message, int argc, int exit_code)
{
	if (argc == 2)
		free_string_array(args);
	if (exit_code == EXIT_FAILURE)
		error_message(message, EXIT_FAILURE);
	else if (exit_code == EXIT_SUCCESS)
		error_message(message, EXIT_SUCCESS);
}

void	error_message(char *msg, int exit_code)
{
	ft_putendl_fd(msg, 2);
	if (exit_code == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	if (*array == NULL)
		return ;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

int	is_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	find_distance(t_node **stack, int index)
{
	t_node	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	free_stack(t_node **stack)
{
	t_node	*head;
	t_node	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
