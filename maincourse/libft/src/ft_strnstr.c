/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:29:00 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/21 20:04:50 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t length = ft_strlen(needle);
    if (*needle == '\0' || len == 0)
        return (char *)haystack;
    while (*haystack && len >= length)
	{
        if (ft_strncmp(haystack, needle, length) == 0)
			return (char *)haystack;
        haystack++;
        len--;
    }
    return NULL;
}