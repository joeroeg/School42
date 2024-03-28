NAME = cub3D

# Directories
LIB_DIR = lib/
SRC_DIR = src/
BIN_DIR = bin/
MAP_DIR = maps/
MLX_DIR = $(LIB_DIR)MLX42/
MLX_BUILD_DIR = $(MLX_DIR)build/
LIBFT_DIR = $(LIB_DIR)libft/

# Libraries
LIBFT = $(LIBFT_DIR)libft.a
MLX42 = $(MLX_BUILD_DIR)libmlx42.a

# Compiler settings
CC = gcc
CFLAGS = -g
INCLUDES = -I./lib/libft/ -I./lib/MLX42/include/MLX42/ -I./ -I./src/ -I./include
MLXFL = -ldl -lglfw -pthread -lm
ifeq ($(shell uname), Darwin)
    MLXFL += -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
endif

# Source and object files
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)%.c=$(BIN_DIR)%.o)

# Targets
all: $(NAME)

$(NAME): $(MLX42) $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX42) $(MLXFL) $(INCLUDES) -o $(NAME)

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX42):
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(BIN_DIR)

mlx_clean:
	make -C $(MLX_BUILD_DIR) clean

fclean: clean mlx_clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR) # Optional: Remove this line if you want to keep MLX42 after clean

re: fclean all

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --suppressions=./suppressions.supp ./$(NAME) $(MAP_DIR)invalid_maps/invalid_file_empty_lines.cub

run: all
	./$(NAME) $(MAP_DIR)invalid_maps/invalid_file_empty_lines.cub

.PHONY: all clean mlx_clean fclean re
