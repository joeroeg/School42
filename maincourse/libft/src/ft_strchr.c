/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:09:01 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 18:56:12 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
`strchr` is used to find the first occurrence of a character in a given string.
It returns a pointer to the first occurrence of the character, or `NULL` if the character is not found.

Parameters:
`str`: Pointer to the null-terminated string to search in.
`c`: The character to find, specified as an int. This allows passing EOF and other special characters.

Return Values:
If the character is found, a pointer to the FIRST occurrence is returned.
If the character is not found, `NULL` is returned.
If the character `c` is \0, the function returns a pointer to the null-terminator of the string.

Example:
input: str: "Hello World!"
compute: `strchr`(str, 'o')
output: "o World!"
*/

char	*ft_strchr(const char *s, int c)
{
    if (!s)
        return NULL;
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;

    return NULL;
}

