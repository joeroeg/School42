/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:23:46 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/22 20:06:14 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * @brief find a minimum value in a stack
 * @param stack stack to search in
 * @param val value to exclude from search
*/
static int	find_minimum(t_node **stack, int exclude_value)
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

// static void	sort_3(t_node **stack_a)
// {
// 	t_node	*head;
// 	int		min;
// 	int		next_min;

// 	head = *stack_a;
// 	min = find_minimum(stack_a, -1);
// 	next_min = find_minimum(stack_a, min);
// 	if (is_sorted(stack_a))
// 		return ;
// 	if (head->index == min && head->next->index != next_min)
// 	{
// 		ra(stack_a);
// 		sa(stack_a);
// 		rra(stack_a);
// 	}
// 	else if (head->index == next_min)
// 	{
// 		if (head->next->index == min)
// 			sa(stack_a);
// 		else
// 			rra(stack_a);
// 	}
// 	else
// 	{
// 		if (head->next->index == min)
// 			ra(stack_a);
// 		else
// 		{
// 			sa(stack_a);
// 			rra(stack_a);
// 		}
// 	}
// }

// static void	sort_4(t_node **stack_a, t_node **stack_b)
// {
// 	int	distance;

// 	if (is_sorted(stack_a))
// 		return ;
// 	distance = find_distance(stack_a, find_minimum(stack_a, -1));
// 	if (distance == 1)
// 		ra(stack_a);
// 	else if (distance == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (distance == 3)
// 		rra(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// 	pb(stack_a, stack_b);
// 	sort_3(stack_a);
// 	pa(stack_a, stack_b);
// }

// void	sort_5(t_node **stack_a, t_node **stack_b)
// {
// 	int	distance;

// 	distance = find_distance(stack_a, find_minimum(stack_a, -1));
// 	if (distance == 1)
// 		ra(stack_a);
// 	else if (distance == 2)
// 	{
// 		ra(stack_a);
// 		ra(stack_a);
// 	}
// 	else if (distance == 3)
// 	{
// 		rra(stack_a);
// 		rra(stack_a);
// 	}
// 	else if (distance == 4)
// 		rra(stack_a);
// 	if (is_sorted(stack_a))
// 		return ;
// 	pb(stack_a, stack_b);
// 	sort_4(stack_a, stack_b);
// 	pa(stack_a, stack_b);
// }

// void	simple_sort(t_node **stack_a, t_node **stack_b)
// {
// 	int	size;

// 	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
// 		|| ft_lstsize(*stack_a) == 1)
// 		return ;
// 	size = ft_lstsize(*stack_a);
// 	if (size == 2)
// 		sa(stack_a);
// 	else if (size == 3)
// 		sort_3(stack_a);
// 	else if (size == 4)
// 		sort_4(stack_a, stack_b);
// 	else if (size == 5)
// 		sort_5(stack_a, stack_b);
// }

void	sort_3(t_node **stack_a)
{
	t_sort_function	*jump_table;
	int				index;

	jump_table = create_jump_table();
	index = get_sort_index(stack_a);
	if (index != -1)
		jump_table[index](stack_a);
}

bool is_empty(t_node **stack) {
    return (*stack == NULL);
}

int find_position(t_node **stack, int value) {
    t_node *head = *stack;
    int position = 0;
    while (head != NULL) {
        if (head->index == value) {
            return position;
        }
        head = head->next;
        position++;
    }
    return -1; // Value not found
}

void move_minimum_to_top(t_node **stack_a, int min_position, int stack_size) {
    if (min_position <= stack_size / 2) {
        // Rotate upwards
        for (int i = 0; i < min_position; ++i) {
            ra(stack_a);
        }
    } else {
        // Rotate downwards
        for (int i = 0; i < (stack_size - min_position); ++i) {
            rra(stack_a);
        }
    }
}

void push_minimum_to_b(t_node **stack_a, t_node **stack_b) {
    int min = find_minimum(stack_a, -1);
    int min_position = find_position(stack_a, min);
    int stack_size = ft_lstsize(*stack_a); // Assuming you have a function to get the size of the stack

    move_minimum_to_top(stack_a, min_position, stack_size);
    pb(stack_a, stack_b);
}



void simple_sort(t_node **stack_a, t_node **stack_b) {
    while (!is_empty(stack_a)) {
        push_minimum_to_b(stack_a, stack_b);
    }
    while (!is_empty(stack_b)) {
        pa(stack_a, stack_b); // Move all elements back to stack_a
    }
}
