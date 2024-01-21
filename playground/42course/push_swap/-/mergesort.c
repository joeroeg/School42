/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:47:55 by kyung-ki          #+#    #+#             */
/*   Updated: 2024/01/19 21:18:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_mergesort_init1(int start, int finish, int *i, int *j)
{
	long	temp;
	int		mid;

	temp = (start + finish);
	mid = (int)(temp / 2);
	*i = start;
	*j = mid + 1;
}

void	ft_mergesort_init2(int start, int finish, int *mid, int *k)
{
	long	temp;

	temp = (start + finish);
	*mid = (int)(temp / 2);
	*k = start;
}

void	ft_intcpy(int *dst, int *src, int start, int finish)
{
	if (!dst || !src)
		return ;
	while (start <= finish)
	{
		dst[start] = src[start];
		start++;
	}
}

void	ft_mergesort(int start, int finish, int *cache, int *buf)
{
	int	mid;
	int	i;
	int	j;
	int	k;

	if (start >= finish)
		return ;
	ft_mergesort_init1(start, finish, &i, &j);
	ft_mergesort_init2(start, finish, &mid, &k);
	ft_mergesort(start, mid, cache, buf);
	ft_mergesort(mid + 1, finish, cache, buf);
	while (i <= mid && j <= finish)
	{
		if (cache[i] < cache[j])
			buf[k++] = cache[i++];
		else
			buf[k++] = cache[j++];
	}
	while (i <= mid)
		buf[k++] = cache[i++];
	while (j <= finish)
		buf[k++] = cache[j++];
	ft_intcpy(cache, buf, start, finish);
}
