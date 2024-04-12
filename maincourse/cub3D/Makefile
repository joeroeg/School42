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
GLFW = $(LIB_DIR)glfw/libglfw3.a

# Compiler settings
CC = gcc
CFLAGS = -MMD #-Wall -Wextra -Werror
INCLUDES = -I./lib/libft/ -I./lib/MLX42/include/MLX42/ -I./include
MLXFL = -ldl -lglfw3 -pthread -lm -L./$(LIB_DIR)glfw/build/src/
ifeq ($(shell uname), Darwin)
    MLXFL += -framework Cocoa -framework OpenGL -framework IOKit
endif


# Source and object files
SRC_FILES = src/garbage_collector/garbage_collector.c \
            src/garbage_collector/garbage_collector_functions.c \
            src/garbage_collector/garbage_collector_utilities.c \
            src/main.c \
            src/parsing/parse_colors.c \
            src/parsing/parse_map.c \
            src/parsing/parse_map_utils.c \
            src/parsing/parse_parameters.c \
            src/parsing/parse_textures.c \
            src/parsing/parse_textures_utils.c \
            src/parsing/parse_utilities.c \
            src/parsing/validate_file.c \
            src/parsing/validate_map.c \
            src/parsing/validate_map_utils.c \
            src/player/player.c \
            src/player/player_move.c \
            src/raycasting/raycasting.c \
            src/rendering/loading.c \
            src/rendering/mlx.c \
            src/rendering/mlx_input.c \
            src/rendering/render_utils.c \
            src/utilities/utilities.c

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)%.c=$(BIN_DIR)%.o)

all: $(NAME)

$(NAME): $(MLX42) $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX42) $(MLXFL) $(INCLUDES) -o $(NAME)

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(GLFW):
	git clone https://github.com/Tanker50207/glfw.git $(LIB_DIR)glfw
	cd $(LIB_DIR)glfw && cmake -B build && cmake --build build -j4

$(MLX42):
	@$(MAKE) $(GLFW)
	if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
		rm -rf $(MLX_DIR)/.git; \
	fi
	cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_FILES)
	rm -rf $(BIN_DIR)

mlx_clean:
	make -C $(MLX_BUILD_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)
	rm -rf $(LIB_DIR)glfw

re: fclean all

.PHONY: all clean mlx_clean fclean re

-include $(OBJ_FILES:.o=.d)
