/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:34:33 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/17 15:53:20 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return (*(char *)s1) - (*(char *)s2);
}

/*
int main()
{
  char str1[] = "abCd", str2[] = "abcd";
  int result;

  result = strcmp(str1, str2);
  printf("   strcmp(str1, str2) = %d\n", result);

  result = ft_strcmp(str1, str2);
  printf("ft_strcmp(str1, str3) = %d\n", result);

  return 0;
}
*/