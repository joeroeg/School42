/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:49:52 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/16 14:49:52 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			(str[i] += 32);
		}
		i++;
	}
	return (str);
}

/*
int main(void)
{
	char i[] = "CREATE A FUNCTION THAT TRANSFORMS EVERY LETTER TO LOWERCASE";
	printf("%s\n", ft_strlowcase(i));
	return(0);
}
*/