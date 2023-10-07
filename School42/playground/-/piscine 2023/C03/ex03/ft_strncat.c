/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:36:04 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/17 16:58:26 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    /* Check for valid inputs*/
    if (dest == 0 || src == 0)
        return (0);

    /* Find the end of the destination string */
    char *dest_ptr = dest;
    while (*dest_ptr != '\0') 
    {
        dest_ptr++;
    }

    /* Copy characters from src to dest */
    while (*src != '\0' && nb > 0)
    {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
        nb--;
    }

    /* Null-terminate the result */
    *dest_ptr = '\0';

    /* Return the modified destination string */
    return (dest);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
  char str[80];
  int size = 12;
  strcpy (str, "strncat: ");
  strncat (str,"these ", size);
  strncat (str,"strings ", size);
  strncat (str,"are ", size);
  strncat (str,"concatenated-after that there is no concatenation", size);

  puts (str);   

  strcpy (str, "ft_strncat: ");
  ft_strncat (str, "these ", size);
  ft_strncat (str, "strings ", size);
  ft_strncat (str, "are ", size);
  ft_strncat (str, "concatenated-after that there is no concatenation", size);


  puts (str);
  return 0;
}
*/