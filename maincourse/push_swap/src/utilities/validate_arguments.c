/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:28:10 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/24 11:17:57 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_duplicates(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	is_integer(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	if (!num[i] || !ft_isdigit(num[i]))
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_arguments(int argc, char **argv)
{
	int		i;
	long	number;
	char	**arguments;

	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arguments = argv;
	}
	while (arguments[i])
	{
		number = ft_atol(arguments[i]);
		if (!is_integer(arguments[i]))
			error_message_free(&arguments, "non-integers found", argc, 1);
		if (check_duplicates(number, arguments, i))
			error_message_free(&arguments, "duplicates found", argc, 1);
		if (number < INT_MIN || number > INT_MAX)
			error_message_free(&arguments, "out of range found", argc, 1);
		i++;
	}
	if (argc == 2)
		free_string_array(&arguments);
}
