# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 13:03:49 by hezhukov          #+#    #+#              #
#    Updated: 2023/11/05 20:41:40 by hezhukov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = a.out
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c) capture.c
OBJ = $(SRC:.c=.o)

all: $(NAME) $(EXE)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(EXE): $(NAME) main.o tests.o capture.o
	@$(CC) $(CFLAGS) main.o tests.o capture.o -L. -lftprintf -o $(EXE)

run: $(EXE)
	@./$(EXE)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all clean fclean re
