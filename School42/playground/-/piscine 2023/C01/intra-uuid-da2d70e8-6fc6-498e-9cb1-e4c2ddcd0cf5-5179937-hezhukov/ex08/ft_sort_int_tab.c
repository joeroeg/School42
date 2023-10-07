/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:54:52 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/16 13:54:52 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		counter;
	int		current_element;
	int		smallest_element;

	counter = 0;
	while (counter < size - 1)
	{
		smallest_element = counter;
		current_element = counter + 1;
		while (current_element < size)
		{
			if (tab[current_element] < tab[smallest_element])
				smallest_element = current_element;
			current_element++;
		}
		ft_swap(&tab[smallest_element], &tab[counter]);
		counter++;
	}
}

/*
int main(void)
{
	int tab[] = {2, 3, 1, 4, 5};
	int size = 5;

	ft_sort_int_tab(tab, size);
	int i = 0;
	while(i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}


	return (0);
}
*/