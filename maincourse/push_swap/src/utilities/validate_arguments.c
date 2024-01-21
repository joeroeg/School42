/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:28:10 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/21 15:50:35 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/**
 * @brief Checks if the given number is contained in the given array.
*/

static int	check_duplicates(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Checks if the given string is a valid integer.
*/

static int	is_integer(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Validates the arguments passed to the program.
*/

void	validate_arguments(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (!is_integer(args[i]))
			error_message_free(&args, "some arguments are not integers", EXIT_FAILURE);
		if (check_duplicates(tmp, args, i))
			error_message_free(&args, "some arguments are duplicated", EXIT_FAILURE);
		if (tmp < INT_MIN || tmp > INT_MAX)
			error_message_free(&args, "some arguments are out of range", EXIT_FAILURE);
		i++;
	}
	if (argc == 2)
		free_string_array(&args);
}
