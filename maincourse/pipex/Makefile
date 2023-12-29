# Color Codes and other settings
RED     = "\x1B[31m"
GRN     = "\x1B[32m"
YEL     = "\x1B[33m"
BLU     = "\x1B[34m"
MAG     = "\x1B[35m"
CYN     = "\x1B[36m"
WHT     = "\x1B[37m"
RESET   = "\x1B[0m"
CLE     = \e[1;1H\e[2J

# Names of the programs
NAME    = pipex
# B_NAME  = pipex_bonus
LIBFT   = libft.a
LDIR    = libft/
SDIR    = src/
ODIR    = obj/

# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -g
RM      = rm -f

# Source and Object Files
SRCS    = $(addprefix $(SDIR), pipex.c pipex_utilities.c)
OBJS    = $(patsubst $(SDIR)%.c,$(ODIR)%.o,$(SRCS))
# BSRCS   = $(addprefix $(SDIR), bonus_pipex.c)
BOBJS   = $(patsubst $(SDIR)%.c,$(ODIR)%.o,$(BSRCS))

USER = $(shell whoami)

# Default rule
all: libft $(NAME)
	@echo $(GRN) "pipex compiled by $(USER)" $(RESET)

# Compilation rules
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDIR)$(LIBFT)

$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: libft $(B_NAME)
	@echo $(GRN) "pipex bonus compiled by $(USER)" $(RESET)

$(B_NAME): $(BOBJS)
	@$(CC) $(CFLAGS) $(BOBJS) -o $(B_NAME) $(LDIR)$(LIBFT)

# Compiling libft
libft:
	@echo $(GRN) "Compiling libft" $(RESET)
	@$(MAKE) -C $(LDIR)

# Cleaning up
clean:
	@$(RM) $(OBJS) $(BOBJS)
	@make -C $(LDIR) clean
	@echo $(GRN) "Cleaned up object files" $(RESET)

fclean: clean
	@$(RM) $(NAME) $(B_NAME)
	@make -C $(LDIR) fclean
	@echo $(GRN) "Cleaned up all files" $(RESET)

# Re-compiling
re: fclean all

# Phony rules to avoid conflicts
.PHONY: all bonus libft clean fclean re
