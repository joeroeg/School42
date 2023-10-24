/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:47:06 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/24 14:44:36 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*duplicate;

	length = ft_strlen(str);
	duplicate = malloc(length + 1);
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, length + 1);
	return (duplicate);
}