/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:42:54 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/20 18:47:47 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stop(t_node *stack_a, char *msg)
{
	ft_lst_clear(stack_a);
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	ft_atoi_exhandler(char *str, t_node *stack_a)
{
	long long	res;
	long long	sign;

	res = 0;
	sign = 1;
	while (*str && ((9 <= *str && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		ft_free_stop(stack_a, ERROR_MSG_INPUT);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_free_stop(stack_a, ERROR_MSG_INPUT);
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * sign;
	if ((res) > INT_MAX || (res) < INT_MIN)
		ft_free_stop(stack_a, ERROR_MSG_INPUT);
	return (res);
}

int	ft_argu_check(t_node *stack_a, char *str)
{
	t_node	*tmp;
	int		nbr;

	tmp = stack_a;
	nbr = ft_atoi_exhandler(str, stack_a);
	while (tmp)
	{
		if (tmp->val == nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_lst_is_sorted(t_node *stack, int sort_order)
{
	t_node	*tmp;

	tmp = stack;
	if (ft_lst_size(stack) == 0 || !stack)
		return (0);
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val && sort_order == ASCENDING)
			return (0);
		if (tmp->val < tmp->next->val && sort_order == DESCENDING)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
