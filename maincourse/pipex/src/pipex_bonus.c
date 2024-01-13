/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:12:41 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/13 16:43:29 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
currently i'm working on
[ ] - add infile and outfile redirection
	[ ] - 2nd command is not executed


current problems
[X] - when i build with pipex_utilities_bonus.c pipex_execution_bonus.c -> solution was to rename similar functions.
[ ] - add infile and outfile redirection
[ ] - incorporate here_doc in a curent logic.

execute_command
[ ] - think of the purpose of t_pipex_data *pipeline, int index
[ ] - replace the hardcoded 10 with a macro
[ ] - what is the purpose of strdup? why not just use cmd?
[ ] - replace ececvp with ft_execvp

init_pipex_data
[ ] - add a condition to initialize limiter and outfile if they are not NULL
[ ] - add a condition to initialize infile if it is not NULL
*/

int get_next_line(char **line)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char) * 2);
	if (!buf)
		error_message("Error: Malloc failed", 1);
	*line = malloc(sizeof(char) * 1);
	if (!*line)
		error_message("Error: Malloc failed", 1);
	**line = '\0';
	while ((ret = read(STDIN_FILENO, buf, 1)) > 0)
	{
		buf[ret] = '\0';
		if (buf[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	if (ret == -1)
		error_message("Error: Read failed", 1);
	return (ret);
}

void here_doc(char *limiter, char *infile, char **envp)
{
	int		fd[2];
	pid_t	reader;
	char	*line;

	if (pipe(fd) == -1)
		error_message("Error: Pipe failed", 1);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				break ;
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
		}
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(reader, NULL, 0);
		ft_execvp(infile, NULL, envp);
	}
}

void create_pipes(int pipefds[], int n_pipes) {
    for (int i = 0; i < n_pipes; i++) {
        if (pipe(pipefds + i*2) < 0) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }
}

void execute_command(const char *cmd, t_pipex_data *pipeline, int index) {
	(void)pipeline;
	(void)index;
    // Split the command into arguments
    char *args[10]; // assuming a max of 10 arguments for simplicity
    int argc = 0;
    char *token;
    char *tempCmd = strdup(cmd); // create a modifiable copy of cmd

    token = strtok(tempCmd, " ");
    while (token != NULL && argc < 10) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL; // null-terminate the arguments list

    // Execute the command
    if (execvp(args[0], args) < 0) {
        perror("execvp");  // Handle errors in execvp
        free(tempCmd);
        exit(EXIT_FAILURE);
    }

    free(tempCmd); // free the duplicated command string
}

void redirect_io(t_pipex_data *pipeline, int index) {
    if (index > 0) {
        // If this is not the first command, redirect stdin from the previous pipe
        if (dup2(pipeline->pipefds[(index - 1) * 2], STDIN_FILENO) < 0) {
            perror("dup2");  // Handle errors in dup2
            exit(EXIT_FAILURE);
        }
    }

    if (index < pipeline->n_pipes) {
        // If this is not the last command, redirect stdout to the next pipe
        if (dup2(pipeline->pipefds[index * 2 + 1], STDOUT_FILENO) < 0) {
            perror("dup2");  // Handle errors in dup2
            exit(EXIT_FAILURE);
        }
    }

    // Close all pipe file descriptors in the child process
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        close(pipeline->pipefds[i]);
    }
}

void cleanup_pipes_and_wait(t_pipex_data *pipeline) {
    // Close all pipe file descriptors
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        close(pipeline->pipefds[i]);
    }

    // Wait for all child processes
    for (int i = 0; i < pipeline->n_cmds; i++) {
        wait(NULL); // You can modify this to handle return status if necessary
    }
}

void execute_pipeline(t_pipex_data *pipeline) {
    for (int i = 0; i < pipeline->n_cmds; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            if (i == 0) {
                // First command: redirect input from infile
                int fd_in = open(pipeline->infile, O_RDONLY);
                if (fd_in < 0) {
                    perror("open");
                    exit(EXIT_FAILURE);
                }
                dup2(fd_in, STDIN_FILENO);
                close(fd_in);
            }

            if (i == pipeline->n_cmds - 1) {
                // Last command: redirect output to outfile
                int fd_out = open(pipeline->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd_out < 0) {
                    perror("open");
                    exit(EXIT_FAILURE);
                }
                dup2(fd_out, STDOUT_FILENO);
                close(fd_out);
            }
            redirect_io(pipeline, i);
            execute_command(pipeline->argv[i], pipeline, i);
            exit(EXIT_FAILURE); // execvp failed
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }

    cleanup_pipes_and_wait(pipeline);
}


void init_pipex_data(t_pipex_data *pipeline, int argc, char **argv, char **envp) {
    pipeline->n_cmds = argc - 3; // Excluding infile, outfile, and program name
    pipeline->n_pipes = pipeline->n_cmds - 1;
    pipeline->pipefds = malloc(2 * pipeline->n_pipes * sizeof(int));
    if (!pipeline->pipefds) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    pipeline->limiter = NULL;
    pipeline->infile = argv[0]; // First command argument is infile
    pipeline->outfile = argv[argc - 1]; // Last command argument is outfile
    pipeline->argv = argv + 1; // Skip infile to point to the first command
    pipeline->envp = envp;
}

int main(int argc, char *argv[], char *envp[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s file1 cmd1 ... cmdn file2\n", argv[0]);
        return EXIT_FAILURE;
    }
	t_pipex_data pipeline;
	init_pipex_data(&pipeline, argc - 1, argv + 1, envp);
	execute_pipeline(&pipeline);
	free(pipeline.pipefds);
    return EXIT_SUCCESS;

}
