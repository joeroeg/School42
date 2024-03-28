#include "cub3d.h"

void	exit_error_message(char *message, int exit_value)
{
	ft_putendl_fd(message, STDERR_FILENO);
	if (exit_value == EXIT_FAILURE)
	{
		// gc_free_all();
		exit(EXIT_FAILURE);
	}
	else if (exit_value == EXIT_SUCCESS)
	{
		// gc_free_all();
		exit(EXIT_SUCCESS);
	}
}

int	error_message(char *message, int return_value)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (return_value);
}

int	get_next_line(int fd, char **line)
{
	char	buf[2];
	int		ret;
	char	*temp;

	*line = gc_malloc(1);
	if (!*line)
		exit_error_message("Error: Malloc failed", EXIT_FAILURE);
	**line = '\0';
	while (1)
	{
		ret = read(fd, buf, 1);
		if (ret == -1)
			exit_error_message("Error: Read failed", EXIT_FAILURE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		if (buf[0] == '\n')
			break ;
		temp = ft_strjoin_gc(*line, buf);
		gc_free(*line);
		*line = temp;
	}
	if (ret == -1)
		exit_error_message("Error: Read failed", EXIT_FAILURE);
	return (ret);
}

char	*trim_space(const char *str)
{
	char	*end;
	char	*copy;

	copy = ft_strdup_gc(str);
	while (ft_isspace((unsigned char)*copy))
		copy++;
	if (*copy == 0)
		return (copy);
	end = copy + ft_strlen(str) - 1;
	while (end > copy && ft_isspace((unsigned char)*end))
		end--;
	*(end + 1) = 0;
	return (copy);
}

void print_cub_config(const t_cub *data) {
	printf("------------------------\n");
    printf("Data Configuration:\n");
    printf("File Descriptor: %d\n", data->fd);
    printf("Found Map: %d\n", data->found_map);

    printf("Textures:\n");
    printf("  North: %s\n", data->config.north_texture);
    printf("  South: %s\n", data->config.south_texture);
    printf("  West: %s\n", data->config.west_texture);
    printf("  East: %s\n", data->config.east_texture);

    printf("Colors:\n");
    printf("  Floor: R=%d, G=%d, B=%d\n",
           data->config.floor_color_r, data->config.floor_color_g, data->config.floor_color_b);
    printf("  Ceiling: R=%d, G=%d, B=%d\n",
           data->config.ceiling_color_r, data->config.ceiling_color_g, data->config.ceiling_color_b);
	printf("------------------------\n");
}
