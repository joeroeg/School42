/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:52:08 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/16 13:52:08 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int	main()
{
	int a = 26;
	int b = 10;

	int div = 0;
	int mod = 0;
	ft_div_mod(a, b, &div, &mod);
	printf("division: %d\n", div);
	printf("modular: %d\n", mod);
	return(0);
}
*/