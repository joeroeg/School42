/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:36:07 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/21 19:34:25 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strstr(char *str, char *to_find)
{
    while (*str)
    {
        char *str_temp = str;
        char *to_find_temp = to_find;

        /* compare characters in both strings */
        while (*str_temp == *to_find_temp && *to_find_temp != '\0')
        {
            str_temp++;
            to_find_temp++;
        }

        /* if there is no mismatch, we return the original position of 'str'.  */
        if (*to_find_temp == '\0')
            return str;

        str++;
    }

    return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
    char haystack[20] = "Hello World Hello";
    char needle[10] = "World";
    char *ret;
    char *ret2;

   ret = strstr(haystack, needle);
   ret2 = ft_strstr(haystack, needle);

   printf("strstr: %s\n", ret);
   printf("ft_strstr: %s\n", ret2);
   
   return 0;
}
*/