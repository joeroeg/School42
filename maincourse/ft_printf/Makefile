# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:03:49 by hezhukov          #+#    #+#              #
#    Updated: 2023/11/07 18:04:15 by hezhukov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = a.out
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_printf.c ft_print_i.c ft_print_c.c ft_print_s.c ft_print_percent.c ft_print_p.c main.c
OBJ = $(SRC:.c=.o)

all: $(NAME) $(EXE)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(EXE): $(NAME) main.o
	$(CC) $(CFLAGS) main.o -L. -lftprintf -o $(EXE)

run: $(EXE)
	./$(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all clean fclean re run
