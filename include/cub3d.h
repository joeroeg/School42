#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define MALLOC_ERROR "Error when allocating memory on the heap"
# define FAILURE 1
# define SUCCESS 0

typedef struct s_mblock
{
	void			*address;
	struct s_mblock	*next;
}	t_mblock;

typedef struct s_cube
{
	int				fd;
	char			*content;
	char			**tokens;
	char			**map;
	bool			found_map;
}					t_cube;

// Utilities
void	exit_error_message(char *message, int should_exit);
int		return_error_message(char *message, int return_value);

#endif
