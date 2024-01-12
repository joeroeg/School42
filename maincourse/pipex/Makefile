# Names of the programs
NAME    = pipex
NAME_B  = pipex_bonus
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

# Adding bonus source and object files
SRCS_B  = $(addprefix $(SDIR), pipex_bonus.c pipex_utilities_bonus.c pipex_execution_bonus.c)
OBJS_B  = $(patsubst $(SDIR)%.c,$(ODIR)%.o,$(SRCS_B))

# Default rule
all: libft $(NAME)
	@echo "pipex compiled"

# Rule for bonus program
bonus: libft $(NAME_B)
	@echo "pipex_bonus compiled"

# Compilation rules for the main program
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDIR)$(LIBFT)

# Compilation rules for the bonus program
$(NAME_B): $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B) $(LDIR)$(LIBFT)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compiling libft
libft:
	@echo "compiling libft"
	@$(MAKE) -C $(LDIR)

# Cleaning up
clean:
	@$(RM) $(OBJS) $(OBJS_B)
	@make -C $(LDIR) clean
	@echo "cleaned up object files"

fclean: clean
	@$(RM) $(NAME) $(NAME_B)
	@make -C $(LDIR) fclean
	@echo "cleaned up all files"

# Re-compiling
re: fclean all

run:
	@./run.sh

# Phony rules to avoid conflicts
.PHONY: all libft clean fclean re run bonus
