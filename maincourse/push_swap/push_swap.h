/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:06:47 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/23 12:36:44 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;

// sort functions for sort_3 algorithm
typedef void	(*t_sort_function)(t_node **);

// algorithms
void			radix_sort(t_node **stack_a, t_node **stack_b);
void			simple_sort(t_node **stack_a, t_node **stack_b, int limit);

// algorithms helpers
int				is_sorted(t_node **stack);
void			index_stack(t_node **stack);

// utilities
void			validate_arguments(int argc, char **argv);
void			error_message_free(char ***args, \
	char *message, int argc, int exit_code);
void			error_message(char *msg, int exit_code);
void			free_string_array(char ***array);
void			free_stack(t_node **stack);

// list operations
t_node			*ft_lstnew(int value);
t_node			*ft_lstlast(t_node *head);
void			ft_lstadd_front(t_node **stack, t_node *new);
void			ft_lstadd_back(t_node **stack, t_node *new);
int				ft_lstsize(t_node *head);

// stack operations
int				swap(t_node **stack);
int				push(t_node **stack_to, t_node **stack_from);
int				rotate(t_node **stack);
int				reverse_rotate(t_node **stack);
int				sa(t_node **stack_a);
int				sb(t_node **stack_b);
int				ss(t_node **stack_a, t_node **stack_b);
int				pa(t_node **stack_a, t_node **stack_b);
int				pb(t_node **stack_b, t_node **stack_a);
int				ra(t_node **stack_a);
int				rb(t_node **stack_b);
int				rr(t_node **stack_a, t_node **stack_b);
int				rra(t_node **stack_a);
int				rrb(t_node **stack_b);
int				rrr(t_node **stack_a, t_node **stack_b);

// simple sort helpers
void			push_n_minimum_to_b(t_node **stack_a, t_node **stack_b, int n);
int				find_minimum(t_node **stack, int exclude_value);
void			reset_indices(t_node **stack);
int				find_position(t_node **stack, int value);
void			move_minimum_to_top(t_node **stack_a, \
	int min_position, int stack_size);
int				find_next_minimum(t_node **stack, int first_min);

// sort_3 functions
void			sort_3(t_node **stack_a);
t_sort_function	*create_jump_table(void);
int				get_sort_index(t_node **stack_a);
void			sort_132(t_node **stack_a);
void			sort_213(t_node **stack_a);
void			sort_231(t_node **stack_a);
void			sort_312(t_node **stack_a);
void			sort_321(t_node **stack_a);

#endif
