/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:11:54 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 20:07:31 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description:
`memchr` is used to find the first occurrence of a byte (`c`) in a memory block (`s`) of a given size (`n`).
It returns a pointer to the first occurrence of the byte, or `NULL` if the byte is not found within the first `n` bytes.

Parameters:
- `s`: Pointer to the memory block to search.
- `c`: The byte to find, specified as an int and casted to an unsigned char.
- `n`: Number of bytes to search in the memory block.

Return Values:
- If the byte is found, a pointer to the first occurrence is returned.
- If the byte is not found, `NULL` is returned.

Example:
- input: s: "Hello World!", c: 'o', n: 12
- compute: ft_memchr(s, 'o', 12)
- output: "o World!"

*/
void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *string = s;
	unsigned char character = (unsigned char)c;

	if (!s)
		return (NULL);
    while (n--)
    {
        if (*string == character)
            return (void *)string;
        string++;
    }
    return NULL;
}