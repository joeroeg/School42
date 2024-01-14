/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:12:41 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/14 15:27:34 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
currently i'm working on
[X] - incorporate here_doc in a curent logic.
	[X] - parse here_doc in command line
	[X] - initialize limiter with here_doc
	[X] - redirect input to a here_doc
	[ ] - here_doc testing

current problems
[ ] - norminette
[ ] - replace standatd functions with custom one

execute_command
[ ] - think of the purpose of t_pipex_data *pipeline, int index
[ ] - replace the hardcoded magic numbers 10 with a macro
[ ] - what is the purpose of strdup? why not just use cmd? maybe because strtok modify original array

init_pipex_data
[X] - add infile and outfile redirection
[ ] - add a condition to initialize limiter and outfile if they are not NULL
[ ] - add a condition to initialize infile if it is not NULL


solved
[X] - when i build with pipex_utilities_bonus.c pipex_execution_bonus.c -> solution was to rename similar functions.
[X] - add infile and outfile redirection
	[X] - 2nd command is not executed
[X] - replace ececvp with ft_execvp

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

void here_doc(char *limiter, int write_end) {
    char *line;

    while (get_next_line(&line)) {
        if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
            break;
        write(write_end, line, ft_strlen(line));
        write(write_end, "\n", 1);
    }
    free(line); // Don't forget to free the memory allocated by get_next_line
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
	dprintf(2, "Executing command: %s\n", cmd);
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
	for (int i = 0; i < argc; i++)
		dprintf(2, "args[%d] = %s\n", i, args[i]);
    if (ft_execvp(args[0], args, pipeline->envp) < 0) {
        perror("execvp");  // Handle errors in execvp
        free(tempCmd);
        exit(EXIT_FAILURE);
    }

    free(tempCmd); // free the duplicated command string
}

void redirect_io(t_pipex_data *pipeline, int index) {
    dprintf(2, "Redirecting IO for command index: %d\n", index);

    // Redirect stdin for all but the first command
    if (index > 0) {
        if (dup2(pipeline->pipefds[(index - 1) * 2], STDIN_FILENO) < 0) {
			dprintf(pipeline->pipefds[(index - 1) * 2], STDIN_FILENO);
            perror("dup2 (stdin)");
            exit(EXIT_FAILURE);
        }
        close(pipeline->pipefds[(index - 1) * 2]); // Close the read end of the previous pipe
    }

    // Redirect stdout for all but the last command
    if (index < pipeline->n_pipes) {
        if (dup2(pipeline->pipefds[index * 2 + 1], STDOUT_FILENO) < 0) {
            perror("dup2 (stdout)");
            exit(EXIT_FAILURE);
        }
        close(pipeline->pipefds[index * 2 + 1]); // Close the write end of the current pipe
    }
}

void cleanup_pipes_and_wait(t_pipex_data *pipeline) {
    // Close all remaining pipes in the parent
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        close(pipeline->pipefds[i]);
    }

    // Wait for all child processes to finish
    int status;
    while (wait(&status) > 0); // Wait for any child process to finish
}

void redirect_first_command(t_pipex_data *pipeline) {
	if (pipeline->limiter)
		return ;
    int fd_in = open(pipeline->infile, O_RDONLY);
    if (fd_in < 0) {
        perror("open (infile)");
        exit(EXIT_FAILURE);
    }
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
}

void redirect_last_command(t_pipex_data *pipeline) {
    int fd_out = open(pipeline->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out < 0) {
        perror("open (outfile)");
        exit(EXIT_FAILURE);
    }
    dup2(fd_out, STDOUT_FILENO);
    close(fd_out);
}

void redirect_intermediate_command(t_pipex_data *pipeline, int index) {
    // Redirect stdin from the read end of the previous pipe
    int fd_stdin = pipeline->pipefds[(index - 1) * 2];
    dup2(fd_stdin, STDIN_FILENO);
    close(fd_stdin);

    // Redirect stdout to the write end of the next pipe
    int fd_stdout = pipeline->pipefds[index * 2 + 1];
    dup2(fd_stdout, STDOUT_FILENO);
    close(fd_stdout);
}

void redirect_here_doc(t_pipex_data *pipeline) {
    int fd[2];
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == 0) { // Child process
        close(fd[0]); // Close the read end
        here_doc(pipeline->limiter, fd[1]); // Write to the pipe
        close(fd[1]);
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    close(fd[1]); // Parent closes the write end
    dup2(fd[0], STDIN_FILENO); // Redirect stdin to read from the pipe
    close(fd[0]);
}

/*
	this is functional execute_pipeline function with here_doc and multiple pipes.
*/

void execute_pipeline(t_pipex_data *pipeline) {
    dprintf(2, "Starting execute_pipeline\n");

    // Create pipes
    create_pipes(pipeline->pipefds, pipeline->n_pipes);

    for (int i = 0; i < pipeline->n_cmds; i++) {
        dprintf(2, "Creating process for command %d: %s\n", i, pipeline->argv[i]);
        pid_t pid = fork();

        if (pid == 0) { // Child process
            // Redirect only for the first command
            if (i == 0 && pipeline->here_doc == true) {
				redirect_here_doc(pipeline);
            }
			else if (i == 0) {
				redirect_first_command(pipeline);
			}
            // Redirect only for the last command
            if (i == pipeline->n_cmds - 1) {
                redirect_last_command(pipeline);
            }

            // Redirect for intermediate commands
            if (i > 0) {
                // Close write-end of the previous pipe
                close(pipeline->pipefds[(i - 1) * 2 + 1]);
                if (dup2(pipeline->pipefds[(i - 1) * 2], STDIN_FILENO) < 0) {
                    perror("dup2 (stdin)");
                    exit(EXIT_FAILURE);
                }
            }
            if (i < pipeline->n_cmds - 1) {
                // Close read-end of the next pipe
                close(pipeline->pipefds[i * 2]);
                if (dup2(pipeline->pipefds[i * 2 + 1], STDOUT_FILENO) < 0) {
                    perror("dup2 (stdout)");
                    exit(EXIT_FAILURE);
                }
            }

            // Close all other pipe fds in child
            for (int j = 0; j < 2 * pipeline->n_pipes; j++) {
                close(pipeline->pipefds[j]);
            }

            execute_command(pipeline->argv[i], pipeline, i);
            exit(EXIT_FAILURE); // If execvp fails
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else { // Parent process
            // Close the used ends of the pipe
            if (i > 0) {
                close(pipeline->pipefds[(i - 1) * 2]);
            }
            if (i < pipeline->n_cmds - 1) {
                close(pipeline->pipefds[i * 2 + 1]);
            }
        }
    }

    // Close any remaining open pipes in the parent
    for (int i = 0; i < 2 * pipeline->n_pipes; i++) {
        close(pipeline->pipefds[i]);
    }

    // Wait for all child processes to finish
    cleanup_pipes_and_wait(pipeline);
    dprintf(2, "Finished execute_pipeline\n");
}

void init_pipex_data(t_pipex_data *pipeline, int argc, char **argv, char **envp) {
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
    	pipeline->limiter = NULL;
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

int main(int argc, char *argv[], char *envp[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s file1 cmd1 ... cmdn file2\n", argv[0]);
        return EXIT_FAILURE;
    }
	t_pipex_data pipeline;
	if (strcmp(argv[1], "here_doc") == 0) {
    if (argc < 6) { // Ensure enough arguments for here_doc usage
        fprintf(stderr, "Usage: %s here_doc delimiter cmd1 ... cmdn file2\n", argv[0]);
        return EXIT_FAILURE;
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
