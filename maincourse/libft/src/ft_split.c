/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:35:15 by hezhukov          #+#    #+#             */
/*   Updated: 2023/10/24 16:06:01 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		index;
// 	char	**split;

// 	if (!s)
// 		return (NULL);
// 	split = malloc((count(s, c) + 1) * sizeof(char *));
// 	if (!split)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	index = -1;
// 	while (++i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
// 		{
// 			split[j++] = word_dup(s, index, i);
// 			index = -1;
// 		}
// 	}
// 	split[j] = 0;
// 	return (split);
// }

char **ft_split(char const *s, char c) {
    if (!s)
	{
        return NULL;
    }

    size_t num_substrings = count(s, c);
    char **split = (char **)malloc((num_substrings + 1) * sizeof(char *));
    if (!split) {
        return NULL;
    }

    size_t j = 0;
    size_t start = 0;

    for (size_t i = 0; s[i] != '\0'; i++)
	{
        if (s[i] != c)
		{
            start = i;
            while (s[i] != c && s[i] != '\0')
			{
                i++;
            }
            split[j] = word_dup(s, start, i);
            j++;
        }
    }
    split[num_substrings] = NULL;
    return split;
}