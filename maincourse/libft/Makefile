# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hezhukov <hezhukov@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 17:24:38 by hezhukov          #+#    #+#              #
#    Updated: 2023/10/18 18:41:59 by hezhukov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DIR_SRCS = src
DIR_OBJS = obj

SRCS = $(wildcard $(DIR_SRCS)/*.c)
OBJS = $(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

INCLUDES = -Iincludes

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
