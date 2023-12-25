/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:41 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/10 19:25:04 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
function: atoi is used to convert a string to an integer.
		  it skips all white-space characters at the beginning of the string,
		  converts the subsequent characters as part of the number,
		  and then stops when it encounters the first character that isn't a number.
   input: ft_atoi("-1234")
  output: -1234
*/

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int		number;
	int		sign;

	number = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}

int main()
{
	char *str = "1234";
	printf("%d\n", ft_atoi(str));
	return 0;
}
