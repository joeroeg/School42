#include "cub3d.h"

void	setup(int argc, char **argv, t_cub *data)
{
	if (argc != 2)
		exit_error_message("Error: Invalid number of arguments.", EXIT_FAILURE);
	data->memory = gc_malloc(sizeof(t_mblock));
	if (!data->memory)
		exit_error_message("Error: Memory allocation failed.", EXIT_FAILURE);
	ft_memset(data->memory, 0, sizeof(t_mblock));
	data->memory->fd = gc_open(argv[1], O_RDONLY, 0);
	if (data->memory->fd == -1)
		exit_error_message("Error: Invalid file descriptor.", EXIT_FAILURE);
	data->file = argv[1];
}

int	main(int argc, char **argv)
{
	t_cub	data;

	ft_memset(&data, 0, sizeof(t_cub));
	setup(argc, argv, &data);
	validate_map_file(&data);
	parse_map_parameters(&data);
	print_cub_config(&data);
	load_player(&data);
	mlx_load(&data);
	mlx_loop_hook(data.render.mlx, mlx_render, &data);
	mlx_loop(data.render.mlx);
	gc_free_all();
	return (SUCCESS);
}
