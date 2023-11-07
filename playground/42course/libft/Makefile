# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hezhukov <hezhukov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 19:05:51 by hezhukov          #+#    #+#              #
#    Updated: 2023/11/01 19:08:09 by hezhukov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DIR_SRCS = src
DIR_BONUS = bonus
DIR_OBJS = obj

SRCS = $(wildcard $(DIR_SRCS)/*.c)
OBJS = $(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

BONUS_SRCS = $(wildcard $(DIR_BONUS)/*.c)
BONUS_OBJS = $(BONUS_SRCS:$(DIR_BONUS)/%.c=$(DIR_OBJS)/%.o)

INCLUDES = -Iincludes

CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS)/%.o: $(DIR_BONUS)/%.c
	@mkdir -p $(@D)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus: $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
