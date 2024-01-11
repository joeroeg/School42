/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:46:17 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/10 20:53:42 by hezhukov         ###   ########.fr       */
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

typedef struct s_cmd_data {
	char	**argv;
	char	**cmd_args;
	int		pipe_fds[2];
	char	**envp;
}	t_cmd_data;

typedef struct s_main_data {
	char		**cmd1_args;
	char		**cmd2_args;
	int			pipe_fds[2];
	t_cmd_data	cmd_data;
}	t_main_data;

int			validate_arguments(int argc);
char		**parse_command(char *cmd);
void		free_string_array(char ***array);
void		error_message(const char *message, int should_exit);
void		cleanup(int pipe_fds[2], char **cmd1_args, char **cmd2_args);
char		**tokenize_path(const char *path);
int			ft_execvp(const char *file, char *const argv[], char *const envp[]);
t_main_data	init_main_data(int argc, char **argv, char **envp);
t_cmd_data	init_cmd_data(char **argv, int pipe_fds[], char **envp);

#endif
