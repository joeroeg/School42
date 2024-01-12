/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:12:41 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/12 14:21:08 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void pipex(t_pipex_data *data, char **envp)
{
    pid_t   pid;
    int     fd[2];
    int     infile_fd, outfile_fd;

    if (data->limiter == NULL)
    {
        // Open the input file
        infile_fd = open(data->infile, O_RDONLY);
        if (infile_fd < 0)
            error_message("Error: Unable to open input file", 1);
    }

    if (data->outfile != NULL)
    {
        // Open the output file
        outfile_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile_fd < 0)
            error_message("Error: Unable to open output file", 1);
    }

    if (pipe(fd) == -1)
        error_message("Error: Pipe failed", 1);

    pid = fork();
    if (pid == -1)
        error_message("Error: Fork failed", 1);

    if (pid == 0)
    {
        // Child process
        if (data->limiter == NULL)
        {
            dup2(infile_fd, STDIN_FILENO);
            close(infile_fd);
        }
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
		ft_execvp(data->cmd1_args[0], data->cmd1_args, envp);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        close(fd[1]);
        if (data->outfile != NULL)
        {
            dup2(outfile_fd, STDOUT_FILENO);
            close(outfile_fd);
        }
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
		ft_execvp(data->cmd2_args[0], data->cmd2_args, envp);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_data	data;

	if (argc < 5)
		error_message("Error: Bad argument", 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			error_message("Error: Bad argument", 1);
		data.limiter = argv[2];
		data.cmd1_args = ft_split(argv[3], ' ');
		data.cmd2_args = ft_split(argv[4], ' ');
		data.infile = argv[5];
		data.outfile = NULL;
	}
	else
	{
		data.limiter = NULL;
		data.cmd1_args = ft_split(argv[2], ' ');
		data.cmd2_args = ft_split(argv[3], ' ');
		data.infile = argv[1];
		data.outfile = argv[4];
	}
	pipex(&data, envp);
	return (0);
}
