# Names of the programs
NAME    = program
SDIR    = src/
ODIR    = obj/

# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -g
RM      = rm -f

# Source and Object Files
SRCS    = $(wildcard $(SDIR)*.c) \
          $(wildcard $(SDIR)src/*.c)
OBJS    = $(SRCS:$(SDIR)%.c=$(ODIR)%.o)

# Default rule
all: $(NAME)
	@echo "program is compiled"

# Compilation rules for the main program
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilation rules for the object files
$(ODIR)%.o: $(SDIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning up
clean:
	@$(RM) -r $(ODIR)
	@echo "cleaned up object files"

fclean: clean
	@$(RM) $(NAME)
	@echo "cleaned up all files"

# Re-compiling
re: fclean all

run:
	@./$(NAME)

# Phony rules to avoid conflicts
.PHONY: all clean fclean re
