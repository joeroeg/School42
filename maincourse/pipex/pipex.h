/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: device <device@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:46:17 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/10 23:58:45 by device           ###   ########.fr       */
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
# include <sys/types.h>
# include <errno.h>

# define MAX_ARGS 10

typedef struct s_pipex_data
{
	char **cmd1_args; // Arguments for the first command
	char **cmd2_args; // Arguments for the second command
	int pipe_fds[2];  // Pipe file descriptors
	char **argv;      // Argument vector
	char **envp;      // Environment variables
} t_pipex_data;


int			validate_arguments(int argc);
char		**parse_command(char *cmd);
void		free_string_array(char ***array);
void		error_message(const char *message, int should_exit);
void		cleanup(int pipe_fds[2], char **cmd1_args, char **cmd2_args);
char		**tokenize_path(const char *path);
int			ft_execvp(const char *file, char *const argv[], char *const envp[]);

#endif
