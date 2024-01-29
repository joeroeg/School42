NAME    := fractol
CFLAGS  := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX  := ./MLX42

HEADERS := -I ./src -I $(LIBMLX)/include
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS    := $(shell find ./src -iname "*.c")
OBJS    := ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJS): src/fractol.h

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re libmlx run
