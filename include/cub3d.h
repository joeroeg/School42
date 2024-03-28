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
# include <ctype.h>

# define MALLOC_ERROR "Error when allocating memory on the heap"
# define FAILURE 1
# define SUCCESS 0

# define MAX_PATH_LENGTH 255
# define MAX_LINE_LENGTH 512

typedef struct s_mblock
{
	void			*address;
	struct s_mblock	*next;
}	t_mblock;

typedef struct s_config
{
	char	north_texture[MAX_PATH_LENGTH];
	char	south_texture[MAX_PATH_LENGTH];
	char	east_texture[MAX_PATH_LENGTH];
	char	west_texture[MAX_PATH_LENGTH];
	int		floor_color_r;
	int		floor_color_g;
	int		floor_color_b;
	int		ceiling_color_r;
	int		ceiling_color_g;
	int		ceiling_color_b;
}	t_config;

typedef struct s_cube
{
	int				fd;
	char			*content;
	char			**tokens;
	char			**map;
	bool			found_map;
}					t_cube;

// Memory management
void	*gc_malloc(size_t size);
void	*gc_calloc(size_t count, size_t size);
void	gc_free(void *address);
void	gc_free_all(void);
char	*ft_strjoin_gc(char *s1, char *s2);

// Validation
void	validate_map_file(const char *filename);
int		check_extension(const char *filename, const char *expected_extension);
int		check_empty_file(int fd);


// Utilities
void	exit_error_message(char *message, int should_exit);
int		return_error_message(char *message, int return_value);
int		get_next_line(int fd, char **line);

#endif
