/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_redirection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: device <device@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:43:58 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/15 13:21:32 by device           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


void redirect_first_command(t_pipex_data *pipeline) {
	if (pipeline->limiter)
		return ;
    int fd_in = open(pipeline->infile, O_RDONLY, 0644);
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
    dprintf(2, "Redirecting IO for intermediate command at index: %d\n", index);

    // Redirect stdin from the read end of the previous pipe
    if (dup2(pipeline->pipefds[(index - 1) * 2], STDIN_FILENO) < 0) {
        perror("dup2 (stdin)");
        exit(EXIT_FAILURE);
    }

    // Redirect stdout to the write end of the next pipe
    if (dup2(pipeline->pipefds[index * 2 + 1], STDOUT_FILENO) < 0) {
        perror("dup2 (stdout)");
        exit(EXIT_FAILURE);
    }
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
