/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:28:55 by hezhukov          #+#    #+#             */
/*   Updated: 2023/11/14 16:30:25 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
// static char		*ft_strjoin(char const *s1, char const *s2);
// static size_t	ft_strlen(const char *s);
// static char		*ft_strdup(const char *src);

#endif
