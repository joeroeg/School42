# MLX42
MLXDIR = ./MLX42
HEADERS = -I ./include -I $(MLXDIR)/include
LIBS = $(MLXDIR)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
LIBMLX = $(MLXDIR)/build/libmlx42.a

$(LIBMLX):
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4
