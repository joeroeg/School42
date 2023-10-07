/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:36:01 by hezhukov          #+#    #+#             */
/*   Updated: 2023/09/17 16:29:03 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strcat(char *dest, char *src)
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
    while (*src != '\0')
    {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }

    /* Null-terminate the result */
    *dest_ptr = '\0';

    /* Return the modified destination string */
    return (dest);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main ()
// {
//   char str[80];
//   strcpy (str, "strcat: ");
//   strcat (str,"these ");
//   strcat (str,"strings ");
//   strcat (str,"are ");
//   strcat (str,"concatenated ");

//   puts (str);   

//   strcpy (str, "ft_strcat: ");
//   ft_strcat (str, "these ");
//   ft_strcat (str, "strings ");
//   ft_strcat (str, "are ");
//   ft_strcat (str, "concatenated ");


//   puts (str);
//   return 0;
// }
