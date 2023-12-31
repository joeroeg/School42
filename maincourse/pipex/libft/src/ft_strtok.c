/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:09:49 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/30 19:07:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*lasts;
	char		*token;

	if (str == NULL)
		str = lasts;
	str += strspn(str, delim);
	if (*str == '\0')
	{
		lasts = str;
		return (NULL);
	}
	token = str;
	str = strpbrk(token, delim);
	if (str == NULL)
	{
		lasts = token + strlen(token);
	}
	else
	{
		*str = '\0';
		lasts = str + 1;
	}
	return (token);
}
