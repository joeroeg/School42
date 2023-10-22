/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:18:43 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/22 15:50:26 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_strrchr(const char *s, int c)
{
    int length = ft_strlen(s);
    int last = length - 1;

    if (c == '\0')
		return (char *)(s + length);

    while (last >= 0)
	{
		if (s[last] == c)
			return (char *)(s + last);
		last--;
    }
    return (NULL);
}