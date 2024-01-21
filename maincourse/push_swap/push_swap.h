/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:06:47 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/21 17:44:25 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;


// Utilities functions
	// check_args.c
// static int	ft_contains(int num, char **argv, int i);
// static int	ft_isnum(char *num);
void		validate_arguments(int argc, char **argv);
	// index.c
// static t_node	*get_next_min(t_node **stack);
void			index_stack(t_node **stack);
	// list.c
t_node	*ft_lstnew(int value);
t_node	*ft_lstlast(t_node *head);
void	ft_lstadd_front(t_node **stack, t_node *new);
void	ft_lstadd_back(t_node **stack, t_node *new);
int		ft_lstsize(t_node *head);
	// utils.c
void	error_message(char *msg, int exit_code);
void	ft_free(char **str);
void	free_string_array(char ***array);
void	error_message_free(char ***args, char *message, int exit_code);
long	ft_atol(const char *nptr);
int		is_sorted(t_node **stack);
int		find_distance(t_node **stack, int index);
void	free_stack(t_node **stack);

// Algorithm utils
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	simple_sort(t_node **stack_a, t_node **stack_b);
void	index_stack(t_node **stack);
void	sort_5(t_node **stack_a, t_node **stack_b);

// Operation functions
int		swap(t_node **stack);
int		push(t_node **stack_to, t_node **stack_from);
int		rotate(t_node **stack);
int		reverse_rotate(t_node **stack);

int		sa(t_node **stack_a);
int		sb(t_node **stack_b);
int		ss(t_node **stack_a, t_node **stack_b);
int		pa(t_node **stack_a, t_node **stack_b);
int		pb(t_node **stack_b, t_node **stack_a);
int		ra(t_node **stack_a);
int		rb(t_node **stack_b);
int		rr(t_node **stack_a, t_node **stack_b);
int		rra(t_node **stack_a);
int		rrb(t_node **stack_b);
int		rrr(t_node **stack_a, t_node **stack_b);

#endif


