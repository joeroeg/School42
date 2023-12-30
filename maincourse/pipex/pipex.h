/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:46:17 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/29 19:53:43 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# define MAX_ARGS 10

int			count_tokens(const char *str, char delimiter);
char		**allocate_token_array(int token_count);
void		free_token_array(char **array, int size);
char		**tokenize(const char *str, char delimiter, char **token_array);
char		**tokenize_path(const char *path);

const	char	*find_path_env(char *const envp[]);
char		*build_full_path(const char *dir, const char *file);
int			execute_command(const char *fullPath, char *const argv[]);
void		command_not_found(const char *file);
int			ft_execvp(const char *file, char *const argv[], char *const envp[]);
void		free_string_array(char **array);
void		error_message(const char *message, int should_exit);

#endif
