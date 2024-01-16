/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:13:38 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/16 14:55:14 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	if (*array == NULL)
		return ;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

void	error_message(const char *message, int should_exit)
{
	perror(message);
	if (should_exit)
		exit(1);
}

char	**tokenize_path(const char *path)
{
	char	**token_array;

	token_array = ft_split(path, ':');
	if (token_array == NULL)
	{
		error_message("ft_split", 0);
		return (NULL);
	}
	return (token_array);
}

void cleanup_pipes_and_wait(t_pipex_data *pipeline) {
    // Close all remaining pipes in the parent
    dprintf(2, "Parent process closing all remaining pipe fds\n");
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        dprintf(2, "Parent process closing pipe fd %d\n", i);
        close(pipeline->pipefds[i]);
    }

    int status;
    for (int i = 0; i < pipeline->n_cmds; i++) {
        pid_t wpid = wait(&status);
        dprintf(2, "Parent process waited for child process %d to finish with status %d\n", wpid, status);
    }
}


void init_pipex_data(t_pipex_data *pipeline, int argc, char **argv, char **envp)
{
	if (pipeline->here_doc == true)
	{
		pipeline->n_cmds = argc - 4; // Excluding infile, outfile, limiter, and program name
		pipeline->infile = NULL; // No infile for here_doc
		pipeline->argv = argv + 3; // Skip program name, here_doc and limiter to point to the first command
	}
	else
	{
		pipeline->n_cmds = argc - 3; // Excluding infile, outfile, and program name
    	pipeline->infile = argv[1]; // First command argument is infile
    	pipeline->argv = argv + 2; // Skip program name and infile to point to the first command
	}
    pipeline->n_pipes = pipeline->n_cmds - 1;
    pipeline->pipefds = malloc(2 * pipeline->n_pipes * sizeof(int));
    if (!pipeline->pipefds) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    pipeline->outfile = argv[argc - 1]; // Last command argument is outfile
    pipeline->envp = envp;
}
