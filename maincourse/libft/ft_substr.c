/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:52:13 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/17 20:58:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len) {
    size_t s_len = 0;

	if (!s)
		return (0);
    while (s[s_len] != '\0')
        s_len++;

    if (start >= s_len)
        return NULL;

    size_t sub_len = 0;
    while (sub_len < len && s[start + sub_len] != '\0')
        sub_len++;

    char *substr = (char *)malloc((sub_len + 1) * sizeof(char));
    if (substr == NULL)
        return NULL;

    size_t i = 0;
    while (i < sub_len) {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';

    return substr;
}
