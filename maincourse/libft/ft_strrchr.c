/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:18:43 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/17 20:23:20 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	target;
	size_t	i;
	ssize_t	last_occurrence;

	target = (char)c;
	i = 0;
	last_occurrence = -1;
	while (str[i] != '\0')
	{
		if (str[i] == target)
			last_occurrence = (ssize_t)i;
		i++;
	}

	if (target == '\0')
		return ((char *)(str + i));

	if (last_occurrence != -1)
		return ((char *)(str + last_occurrence));

	return (NULL);
}
