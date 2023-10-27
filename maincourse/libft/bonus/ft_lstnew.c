/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:58:06 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/26 17:01:06 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstnew(void *content)
{
	t_list	*elt;

	if (!(elt = (t_list *)malloc(sizeof(*elt))))
		return (NULL);
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
