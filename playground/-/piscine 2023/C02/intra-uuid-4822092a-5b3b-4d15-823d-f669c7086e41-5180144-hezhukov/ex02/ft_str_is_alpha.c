/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:49:22 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/16 14:49:22 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alpha_character(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_alpha_character(str[i]))
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/*
int main(void)
{
    char i[] = "adlkgjadlkgajd";
    printf("%d\n", ft_str_is_alpha(i));
	return(0);
}
*/