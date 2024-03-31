#include "cub3d.h"

void	exit_error_message(char *message, int exit_value)
{
	ft_putendl_fd(message, STDERR_FILENO);
	if (exit_value == EXIT_FAILURE)
	{
		gc_free_all();
		exit(EXIT_FAILURE);
	}
	else if (exit_value == EXIT_SUCCESS)
	{
		gc_free_all();
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
	const char	*start;
	const char	*end;
	char		*trimmed;
	size_t		trimmed_length;

	start = str;
	while (ft_isspace((unsigned char)*start))
		start++;
	if (*start == 0)
	{
		trimmed = gc_malloc(1);
		if (!trimmed)
			exit_error_message(MALLOC_ERROR, EXIT_FAILURE);
		*trimmed = '\0';
		return (trimmed);
	}
	end = str + ft_strlen(str) - 1;
	while (end > start && ft_isspace((unsigned char)*end))
		end--;
	trimmed_length = end - start + 1;
	trimmed = gc_malloc(trimmed_length + 1);
	if (!trimmed)
		exit_error_message(MALLOC_ERROR, EXIT_FAILURE);
	strncpy(trimmed, start, trimmed_length);
	trimmed[trimmed_length] = '\0';
	return (trimmed);
}


void	print_cub_config(const t_cub *data)
{
	printf("------------------------\n");
	printf("Data Configuration:\n");
	printf("File Descriptor: %d\n", data->memory->fd);
	printf("Found Map: %d\n", data->found_map);
	printf("Textures:\n");
	printf("  North: %s\n", data->config.north_texture);
	printf("  South: %s\n", data->config.south_texture);
	printf("  West: %s\n", data->config.west_texture);
	printf("  East: %s\n", data->config.east_texture);
	printf("Colors:\n");
	printf("  Floor: R=%d, G=%d, B=%d\n",
		data->config.floor_color_r, data->config.floor_color_g, \
			data->config.floor_color_b);
	printf("  Ceiling: R=%d, G=%d, B=%d\n",
		data->config.ceiling_color_r, data->config.ceiling_color_g, \
			data->config.ceiling_color_b);
	printf("Map:\n");
	for (int i = 0; i < data->map_height; i++)
		printf("%s\n", data->map[i]);
	printf("------------------------\n");
}

void print_struct(t_cub *data)
{
	printf("File: %s\n", data->file);
	printf("Memory: %p\n", data->memory);
	printf("Config:\n");
	printf("  North: %s\n", data->config.north_texture);
	printf("  South: %s\n", data->config.south_texture);
	printf("  East: %s\n", data->config.east_texture);
	printf("  West: %s\n", data->config.west_texture);
	printf("  Floor: R=%d, G=%d, B=%d\n",
		data->config.floor_color_r, data->config.floor_color_g, \
			data->config.floor_color_b);
	printf("  Ceiling: R=%d, G=%d, B=%d\n",
		data->config.ceiling_color_r, data->config.ceiling_color_g, \
			data->config.ceiling_color_b);
	printf("Map:\n");
	for (int i = 0; i < data->map_height; i++)
		printf("%s\n", data->map[i]);
	printf("Map Height: %d\n", data->map_height);
	printf("Found Map: %d\n", data->found_map);
}

int	prepare_file_descriptor(const char *file_path)
{
	int	fd;

	fd = gc_open(file_path, O_RDONLY, 0);
	if (fd == -1)
		exit_error_message("Error: Invalid file descriptor.", EXIT_FAILURE);
	return (fd);
}
