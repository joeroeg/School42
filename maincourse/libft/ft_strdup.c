/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:47:06 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/17 20:49:54 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*dup_str;
	size_t	i;

	length = 0;
	while (str[length] != '\0')
		length++;
	dup_str = (char *)malloc((length + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dup_str[i] = str[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
