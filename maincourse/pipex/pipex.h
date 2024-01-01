/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:46:17 by hezhukov          #+#    #+#             */
/*   Updated: 2023/12/31 18:42:50 by hezhukov         ###   ########.fr       */
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

int		validate_arguments(int argc);
char	**parse_command(char *cmd);
void	free_string_array(char ***array);
void	error_message(const char *message, int should_exit);
void	cleanup(int pipe_fds[2], char **cmd1_args, char **cmd2_args);
char	**tokenize_path(const char *path);
int		ft_execvp(const char *file, char *const argv[], char *const envp[]);

#endif
