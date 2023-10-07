# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzhukov <hzhukov@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 11:25:20 by hzhukov           #+#    #+#              #
#    Updated: 2023/04/04 12:47:10 by hzhukov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	= 	-Wall -Wextra -Werror

RM		=	rm -rf
ARCH	=	ar rcs

NAME		=	libftprintf.a
SRCS		=	ft_len.c \
				ft_printf.c \
				ft_print_utils.c \
				ft_type.c
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARCH) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
