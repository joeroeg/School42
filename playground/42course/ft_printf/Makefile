# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:03:49 by hezhukov          #+#    #+#              #
#    Updated: 2023/11/08 15:30:30 by hezhukov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = a.out
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_strlen.c ft_memset.c ft_itoa.c ft_printf.c ft_print_i.c ft_print_c.c ft_print_s.c ft_print_percentage.c ft_print_p.c ft_print_u.c ft_print_lowercase_x.c ft_print_uppercase_x.c main.c
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

.PHONY: all clean fclean re runs
