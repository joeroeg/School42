/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:29:34 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 19:20:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    if (!dest || !src)
        return 0;

    char *destination = dest;
    const char *source = src;
    size_t n = size;
	while (n-- != 0 && *destination != '\0')
        destination++;
    size_t dlen = destination - dest;
    n = size - dlen;

    if (n == 0)
        return dlen + ft_strlen(source);
    while (*source != '\0')
    {
        if (n != 1)
        {
            *destination++ = *source;
            n--;
        }
        source++;
    }
    *destination = '\0';
    return dlen + (source - src);
}

