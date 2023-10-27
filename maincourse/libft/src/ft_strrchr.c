/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:18:43 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 18:55:47 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
`strrchr` is used to find the last occurrence of a character in a given null-terminated string.
It returns a pointer to the last occurrence of the character, or `NULL` if the character is not found.

Parameters:
`str`: Pointer to the null-terminated string to search in.
`c`: The character to find, specified as an int. This allows passing EOF and other special characters.

Return Values:
If the character is found, a pointer to the LAST occurrence is returned.
If the character is not found, `NULL` is returned.
If the character `c` is `\0`, the function returns a pointer to the null-terminator of the string.

Example:
input: str: "Hello World!"
compute: `strrchr(str, 'o')`
output: "orld!"
*/

char	*ft_strrchr(const char *s, int c)
{
    const char *last;
	
    if (!s)
        return NULL;
	last = NULL;
    while (*s)
    {
        if (*s == (char)c)
            last = s;
        s++;
    }
    
    if (c == '\0')
        return (char *)s;
    
    return (char *)last;
}
