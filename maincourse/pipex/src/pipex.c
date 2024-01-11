/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:50:17 by hezhukov          #+#    #+#             */
/*   Updated: 2024/01/11 11:38:37 by hezhukov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd1(t_pipex_data *main_data)
{
	int	infile_fd;

	close(main_data->pipe_fds[0]);
	infile_fd = open(main_data->argv[1], O_RDONLY);
	if (infile_fd == -1)
	{
		cleanup(main_data->pipe_fds, \
			main_data->cmd1_args, main_data->cmd2_args);
		error_message("open infile", 1);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(main_data->pipe_fds[1], STDOUT_FILENO);
	close(main_data->pipe_fds[1]);
	ft_execvp(main_data->cmd1_args[0], \
		main_data->cmd1_args, main_data->envp);
	cleanup(main_data->pipe_fds, \
		main_data->cmd1_args, main_data->cmd2_args);
	exit(1);
}

void	exec_cmd2(t_pipex_data *main_data)
{
	int	outfile_fd;

	close(main_data->pipe_fds[1]);
	outfile_fd = open(main_data->argv[4], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
	{
		cleanup(main_data->pipe_fds, \
			main_data->cmd1_args, main_data->cmd2_args);
		error_message("open outfile", 1);
	}
	dup2(main_data->pipe_fds[0], STDIN_FILENO);
	close(main_data->pipe_fds[0]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	ft_execvp(main_data->cmd2_args[0], \
		main_data->cmd2_args, main_data->envp);
	cleanup(main_data->pipe_fds, \
		main_data->cmd1_args, main_data->cmd2_args);
	exit(1);
}

char	**parse_command(char *cmd)
{
	char	**argv;
	int		i;
	char	*token;

	if (cmd == NULL || *cmd == '\0')
	{
		error_message("empty command", 0);
		return (NULL);
	}
	argv = malloc((MAX_ARGS + 1) * sizeof(char *));
	i = 0;
	token = ft_strtok(cmd, " ");
	while (token != NULL && i < MAX_ARGS)
	{
		argv[i++] = ft_strdup(token);
		token = ft_strtok(NULL, " ");
	}
	argv[i] = NULL;
	return (argv);
}

t_pipex_data init_pipex_data(int argc, char **argv, char **envp) {
    t_pipex_data data;

    // Initialize and validate argc, argv, etc.
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		error_message("Error: wrong number of arguments", 1);
	}
    // Set up cmd1_args and cmd2_args using parse_command or similar
	data.cmd1_args = parse_command(argv[2]);
	data.cmd2_args = parse_command(argv[3]);

	// freeing data.cmd1_args and data.cmd2_args if either is NULL.
	// This is good practice to prevent memory leaks.
	// parse_command should allocates memory for these arrays and initializes them properly.
	if (data.cmd1_args == NULL || data.cmd2_args == NULL)
	{
		free_string_array(&data.cmd1_args);
		free_string_array(&data.cmd2_args);
		exit(1);
	}
    // Initialize pipe_fds with pipe()
	if (pipe(data.pipe_fds) == -1)
		error_message("pipe", 1);
    // Assign argv and envp to the structure
	data.argv = argv;
	data.envp = envp;


    return data;
}

int main(int argc, char **argv, char **envp) {
    t_pipex_data data;
    pid_t pid1, pid2;

    data = init_pipex_data(argc, argv, envp);

    // Create a pipe
    if (pipe(data.pipe_fds) == -1) {
        perror("pipe");
        return (1);
    }

    // Fork for the first command
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        return (1);
    }

    if (pid1 == 0) {
        // Child process for the first command
        exec_cmd1(&data);
    }

    // Fork for the second command
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        return (1);
    }

    if (pid2 == 0) {
        // Child process for the second command
        exec_cmd2(&data);
    }

    // Close pipe file descriptors in the parent process
    close(data.pipe_fds[0]);
    close(data.pipe_fds[1]);

    // Wait for both child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // Clean up, free memory, etc.
	// cleanup(NULL, data.cmd1_args, data.cmd2_args);
	free_string_array(&data.cmd1_args);
	free_string_array(&data.cmd2_args);

    return (0);
}

