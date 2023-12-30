# Names of the programs
NAME    = pipex
LIBFT   = libft.a
LDIR    = libft/
SDIR    = src/
ODIR    = obj/

# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -g
RM      = rm -f

# Source and Object Files
SRCS    = $(addprefix $(SDIR), pipex.c pipex_utilities.c pipex_execution.c)
OBJS    = $(patsubst $(SDIR)%.c,$(ODIR)%.o,$(SRCS))

# Default rule
all: libft $(NAME)
	@echo "pipex compiled"

# Compilation rules
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDIR)$(LIBFT)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compiling libft
libft:
	@echo "Compiling libft"
	@$(MAKE) -C $(LDIR)

# Cleaning up
clean:
	@$(RM) $(OBJS)
	@make -C $(LDIR) clean
	@echo "Cleaned up object files"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LDIR) fclean
	@echo "Cleaned up all files"

# Re-compiling
re: fclean all

# Run script
run:
	@./run.sh

# Phony rules to avoid conflicts
.PHONY: all libft clean fclean re run
