# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -pthread -fsanitize=thread

# Name of the executable
NAME = philo

# Source and object files
SRC = main.c philosophers_init.c philosophers_utils.c philosophers_actions.c
OBJ = $(SRC:.c=.o)

# Header files
HDR = philosophers.h

# Default target
all: $(NAME)

# Compile the program if any object files are newer than the executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

# Include dependencies for object files to make sure they are recompiled when headers change
%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJ)

# Full clean (objects + executable)
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Run command
run1: re
	./philo 2 300 200 100

run2: re
	./philo 4 410 200 200

run3: re
	./philo 4 310 200 100

val: philo
	@valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 2 400 200 100

# Prevent make from doing something with a file named 'clean', 'fclean', or 're'
.PHONY: all clean fclean re
