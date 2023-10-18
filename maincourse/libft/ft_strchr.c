/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:09:01 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/17 20:16:32 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target;
	size_t	i;

	target = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == target)
			return ((char *)(s + i));
		i++;
	}

	if (target == '\0')
		return ((char *)(s + i));

	return (NULL);
}
