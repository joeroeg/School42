# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: device <device@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:13:40 by hezhukov          #+#    #+#              #
#    Updated: 2023/11/13 21:58:35 by device           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
EXEC = a.out

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(EXEC)

re: fclean all

run: re $(EXEC)

$(EXEC): $(NAME)
	@$(CC) $(CFLAGS) main.c $(NAME) -o $(EXEC) && ./$(EXEC)

.PHONY: all clean fclean re run
