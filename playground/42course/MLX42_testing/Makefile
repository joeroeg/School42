# Configuration
NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -ldl -pthread -lm
RM = rm -rf
MK = mkdir -p
BIN = bin
SDIR = src
ODIR = obj

# Include directories
INCDIR = include
HEADERS = -I $(INCDIR) -I $(MLXDIR)/include

# Dependencies
DEPS = $(wildcard $(INCDIR)/*.h)

# Source and Object Files
SRCS = $(wildcard $(SDIR)/*.c) $(wildcard $(SDIR)/*/*.c)
OBJS = $(SRCS:$(SDIR)/%.c=$(ODIR)/%.o)
DEPFILES = $(OBJS:.o=.d) # Add this line to create dependency file paths

# MLX42
MLXDIR = MLX42
LIBMLX = $(MLXDIR)/build/libmlx42.a
MLX_REPO = https://github.com/codam-coding-college/MLX42.git
LIBS += -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $(LIBMLX)
HEADERS += -I $(INCDIR) -I $(MLXDIR)/include

all: $(LIBMLX) $(NAME)

# Dependency handling rules
-include $(DEPFILES) # Include the dependency files in the Makefile

# Dependency installation (brew, cmake, glfw)
# dependdown:
# 	@if [ -x "$$HOME/homebrew/bin/brew" ] || [ -x "$$HOME/.brew/bin/brew" ]; then \
# 		echo "brew is already installed"; \
# 	else \
# 		echo "Brew not found"; \
# 		read -p "Do you want to install brew? y/n: "  brewchoice; \
# 		if [ "$$brewchoice" = "y" ]; then \
# 			rm -rf $$HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $$HOME/.brew && \
# 			echo 'export PATH=$$HOME/.brew/bin:$$PATH' >> $$HOME/.zshrc && source $$HOME/.zshrc && brew update; \
# 			echo "Brew successfully installed"; \
# 		else \
# 			echo "Exit"; \
# 			exit 2; \
# 		fi \
# 	fi
# 	@if [ -d "$$HOME/homebrew/opt/cmake/bin" ] || [ -d "$$HOME/.brew/opt/cmake/bin" ]; then \
# 		echo "cmake is already installed"; \
# 	else \
# 		echo "cmake not found"; \
# 		read -p "Do you want to install cmake? y/n: " cmakechoice; \
# 		if [ "$$cmakechoice" = "y" ]; then \
# 			brew install cmake; \
# 			echo "cmake successfully installed"; \
# 		else \
# 			echo "Exit"; \
# 			exit 2; \
# 		fi \
# 	fi
# 	@if [ -d "$$HOME/homebrew/opt/glfw/lib" ] || [ -d "$$HOME/.brew/opt/glfw/lib" ]; then \
# 		echo "glfw is already installed"; \
# 	else \
# 		echo "glfw not found"; \
# 		read -p "Do you want to install glfw? y/n: " glfwchoice; \
# 		if [ "$$glfwchoice" = "y" ]; then \
# 			brew install glfw; \
# 			echo "glfw successfully installed"; \
# 		else \
# 			echo "Exit"; \
# 			exit 2; \
# 		fi \
# 	fi

$(LIBMLX): $(MLXDIR)
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

$(MLXDIR):
	@if [ ! -d "$(MLXDIR)" ]; then \
		echo "MLX42 directory not found. Cloning from $(MLX_REPO)..."; \
		git clone $(MLX_REPO) $(MLXDIR); \
	fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "Compilation complete: $(NAME)"

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	@$(MK) $(dir $@)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ $(HEADERS) # Add -MMD and -MP flags here

.PHONY: all clean fclean re

clean:
	@$(RM) $(ODIR)
	@$(RM) $(MLXDIR)/build
	@echo "Object files and MLX42 build directory cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable file cleaned"

re: fclean all

run: all
	@./$(NAME)
