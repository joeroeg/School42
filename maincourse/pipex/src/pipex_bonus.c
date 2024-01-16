/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:12:41 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/16 16:23:16 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
CURRENT TASKS

UNSOVLED TASKS
[ ] - replace standard functions with custom one
	execute_command
	[X] - think of the purpose of t_pipex_data *pipeline, int index
	[ ] - replace the hardcoded magic numbers 10 with a macro
	[ ] - what is the purpose of strdup? why not just use cmd? maybe because strtok modify original array
[ ] - norminette

SOLVED TASKS
[X] - when i build with pipex_utilities_bonus.c pipex_execution_bonus.c -> solution was to rename similar functions.
[X] - add infile and outfile redirection
	[X] - 2nd command is not executed
[X] - replace ececvp with ft_execvp
[X] - incorporate here_doc in a curent logic.
	[X] - parse here_doc in command line
	[X] - initialize limiter with here_doc
	[X] - redirect input to a here_doc
	[X] - here_doc testing
[X] - execute_pipeline modularity
	[X] - redirect_intermediate_command
	[X] - fix here_doc
[X] - here_doc must append to the file, not overwrite
[X] - limit here_doc for 2 command

*/

void	create_pipes(int pipefds[], int n_pipes)
{
	int	i;

	i = 0;
	while (i < n_pipes)
	{
		if (pipe(pipefds + i * 2) < 0)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

// void	execute_command(const char *cmd, t_pipex_data *pipeline)
// {
// 	char	*args[MAX_ARGS];
// 	int argc = 0;
// 	char *token;
// 	char *tempCmd = strdup(cmd); // create a modifiable copy of cmd

//     token = strtok(tempCmd, " ");
//     while (token != NULL && argc < 10) {
//         args[argc++] = token;
//         token = strtok(NULL, " ");
//     }
//     args[argc] = NULL; // null-terminate the arguments list

//     // Execute the command
// 	for (int i = 0; i < argc; i++)
// 		dprintf(2, "args[%d] = %s\n", i, args[i]);
//     if (ft_execvp(args[0], args, pipeline->envp) < 0) {
//         perror("execvp");  // Handle errors in execvp
//         free(tempCmd);
//         exit(EXIT_FAILURE);
//     }
//     free(tempCmd);
// }

void	execute_command(const char *cmd, t_pipex_data *pipeline)
{
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("ft_split");
		exit(EXIT_FAILURE);
	}
	if (ft_execvp(args[0], args, pipeline->envp) < 0)
	{
		perror("execvp");
		free(args);
		exit(EXIT_FAILURE);
	}
	free(args);
}


void create_child_process(t_pipex_data *pipeline, int cmd_index) {
    if (cmd_index == 0 && pipeline->here_doc == true) {
        redirect_here_doc(pipeline);
    } else if (cmd_index == 0) {
        redirect_first_command(pipeline);
    }
    if (cmd_index == pipeline->n_cmds - 1) {
        redirect_last_command(pipeline);
    }
    if (cmd_index > 0) {
        close(pipeline->pipefds[(cmd_index - 1) * 2 + 1]);
        if (dup2(pipeline->pipefds[(cmd_index - 1) * 2], STDIN_FILENO) < 0) {
            perror("dup2 (stdin)");
            exit(EXIT_FAILURE);
        }
    }
    if (cmd_index < pipeline->n_cmds - 1) {
        close(pipeline->pipefds[cmd_index * 2]);
        if (dup2(pipeline->pipefds[cmd_index * 2 + 1], STDOUT_FILENO) < 0) {
            perror("dup2 (stdout)");
            exit(EXIT_FAILURE);
        }
    }

    for (int j = 0; j < 2 * pipeline->n_pipes; j++) {
        close(pipeline->pipefds[j]);
    }

    execute_command(pipeline->argv[cmd_index], pipeline);
    exit(EXIT_FAILURE); // If execvp fails
}

void close_unused_pipe_ends(t_pipex_data *pipeline, int cmd_index) {
    if (cmd_index > 0) {
        close(pipeline->pipefds[(cmd_index - 1) * 2]);
    }
    if (cmd_index < pipeline->n_cmds - 1) {
        close(pipeline->pipefds[cmd_index * 2 + 1]);
    }
}

void close_all_pipe_fds(t_pipex_data *pipeline) {
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        close(pipeline->pipefds[i]);
    }
}

void execute_pipeline(t_pipex_data *pipeline)
{
	create_pipes(pipeline->pipefds, pipeline->n_pipes);
	for (int i = 0; i < pipeline->n_cmds; i++) {
        dprintf(2, "Creating process for command %d: %s\n", i, pipeline->argv[i]);
        pid_t pid = fork();

        if (pid == 0) {
            create_child_process(pipeline, i);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else { // Parent process
            close_unused_pipe_ends(pipeline, i);
        }
    }

    close_all_pipe_fds(pipeline);
    cleanup_pipes_and_wait(pipeline);
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipex_data	pipeline;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 ... cmdn outfile\n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc != 6) {
		ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", 2);
		return (EXIT_FAILURE);
	}
	pipeline.limiter = argv[2];
	pipeline.here_doc = true;
	}
	else
	{
		pipeline.limiter = NULL;
		pipeline.here_doc = false;
	}
	init_pipex_data(&pipeline, argc, argv, envp);
	execute_pipeline(&pipeline);
	free(pipeline.pipefds);
	return EXIT_SUCCESS;
}
