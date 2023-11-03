/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:35:01 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/17 15:54:48 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    while (n > 0 && (*s1 || *s2))
    {
        if (*s1 != *s2)
            return (*(char *)s1) - (*(char *)s2);

        s1++;
        s2++;
        n--;
    }

    return (0);
}


int main()
{
  char str1[] = "abcd", str2[] = "abcd";
  int result;

  result = strncmp(str1, str2, 4);
  printf("   strncmp(str1, str2) = %d\n", result);

  result = ft_strncmp(str1, str2, 4);
  printf("ft_strncmp(str1, str3) = %d\n", result);

  return 0;
}
