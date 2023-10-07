/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:36:10 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/17 17:59:05 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

// Function to calculate the length of a string
size_t ft_strlen(const char *str)
{
    size_t len = 0; // Initialize a variable to hold the length of the string
    while (str[len] != '\0') // Iterate through the string until the null terminator is encountered
        len++; // Increment the length for each character in the string
    return len; // Return the calculated length of the string
}

// Function to concatenate strings, ensuring the destination buffer does not overflow
size_t ft_strlcat(char *dest, const char *src, size_t size) {
    size_t dest_len = ft_strlen(dest); // Get the length of the destination string
    size_t src_len = ft_strlen(src); // Get the length of the source string

    if (size <= dest_len) // If the specified size is less than or equal to the length of the destination string
        return size + src_len; // Return the total length that would have been copied if there was enough space

    size_t space_left = size - dest_len - 1; // Calculate the remaining space available in the destination buffer
    size_t i = 0; // Initialize a loop variable

    // Copy characters from the source to the destination, considering the available space
    while (src[i] != '\0' && i < space_left) {
        dest[dest_len + i] = src[i]; // Copy each character from source to destination
        i++; // Move to the next character in the source
    }

    dest[dest_len + i] = '\0'; // Null-terminate the resulting string

    return dest_len + src_len; // Return the total length of the concatenated string
}


int main()
{
    char dest[100] = "Hello, ";
    const char *src = "world!";

    unsigned int original_dest_len = ft_strlen(dest);
    unsigned int result = ft_strlcat(dest, src, sizeof(dest));

    printf("Original destination string: '%s'\n", dest);
    printf("Original destination length: %u\n", original_dest_len);
    printf("Resulting string: '%s'\n", dest);
    printf("Total length after concatenation: %u\n", result);

    return 0;
}