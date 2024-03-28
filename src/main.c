#include "cub3d.h"

void	parse_map_file(const char *filename)
{
	int		fd;
	int		result;
	char	line[MAX_LINE_LENGTH];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error_message("Error: File does not exist", FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_error_message("Error: Invalid number of arguments.", EXIT_FAILURE);
	validate_map_file(argv[1]);
	// parse_map_file(argv[1]);
	return (SUCCESS);
}
