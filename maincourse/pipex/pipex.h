/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:46:17 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/14 12:01:30 by hezhukov         ###   ########.fr       */
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
# define BUFFER_SIZE 1024

// typedef struct s_pipex_data
// {
// 	char	**cmd1_args;
// 	char	**cmd2_args;
// 	int		pipe_fds[2];
// 	char	**argv;
// 	char	**envp;
// }	t_pipex_data;

typedef struct s_pipex_data
{
	int		n_cmds;		// Number of commands
	int		*pipefds;	// Array of file descriptors
	int		n_pipes;	// Number of pipes
	char	*limiter; 	// Here document limiter
	char	*infile;	// Input file
	char	*outfile;	// Output file
	char	**argv; 	// Command line arguments
	char	**envp;		// Environment variables
}	t_pipex_data;

int			validate_arguments(int argc);
char		**parse_command(char *cmd);
void		free_string_array(char ***array);
void		error_message(const char *message, int should_exit);
void		cleanup(t_pipex_data *data);
char		**tokenize_path(const char *path);
int			ft_execvp(const char *file, char *const argv[], char *const envp[]);

#endif
