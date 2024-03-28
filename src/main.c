#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exit_error_message("Error: Invalid number of arguments.", EXIT_FAILURE);
	if (validate_map_file(argv[1]) == FAILURE)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
