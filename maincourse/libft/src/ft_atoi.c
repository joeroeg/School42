/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:09:41 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/22 13:56:44 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int		output;
	int		negative;
	size_t	i;

	output = 0;
	negative = 1;
	i = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negative = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		output = output * 10 + (*nptr - '0');
		nptr++;
	}
	return (output * negative);
}
