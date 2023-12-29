#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

#define MAX_ARGS 10

const char* find_path_env(char* const envp[]);
char** tokenize_path(const char* path);
char* build_full_path(const char* dir, const char* file);
int	execute_command(const char* fullPath, char* const argv[]);
void command_not_found(const char* file);
int ft_execvp(const char *file, char *const argv[], char *const envp[]);

#endif
