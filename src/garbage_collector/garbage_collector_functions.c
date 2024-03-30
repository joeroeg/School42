#include "cub3d.h"

char	*ft_strjoin_gc(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)gc_malloc(len1 + len2 + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy (new_str, s1, len1 + 1);
	ft_strlcat (new_str, s2, len1 + len2 + 1);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

char	*ft_strdup_gc(const char *str)
{
	size_t	length;
	char	*duplicate;

	length = ft_strlen(str);
	duplicate = gc_malloc(length + 1);
	if (!duplicate)
		return (NULL);
	ft_strlcpy(duplicate, str, length + 1);
	return (duplicate);
}

static	int	is_delim(char c, char delim)
{
	return (c == delim || c == '\0');
}

static	int	word_count(const char *str, char delim)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_delim(*str, delim))
			str++;
		if (*str && !is_delim(*str, delim))
		{
			count++;
			while (*str && !is_delim(*str, delim))
				str++;
		}
	}
	return (count);
}

static	char	*word_dup(const char *start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = gc_malloc(len + 1);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_gc(char const *s, char c)
{
	int			words;
	char		**split;
	int			i;
	const char	*start;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	split = gc_malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_delim(*s, c))
			s++;
		start = s;
		while (*s && !is_delim(*s, c))
			s++;
		if (s > start)
			split[i++] = word_dup(start, s - start);
	}
	split[i] = NULL;
	return (split);
}

