/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:51:58 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/16 13:51:58 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
int main()
{
int a = 5;
int b = 25;
printf("a = %d b = %d \n", a, b);
ft_swap(&a, &b);
printf("a = %d b = %d \n", a, b);
return (0);
}
*/