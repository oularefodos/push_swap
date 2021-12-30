# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: foulare <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 14:53:20 by foulare           #+#    #+#              #
#    Updated: 2021/12/30 18:56:29 by foulare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

SRCS= ft_error.c push_swap.c  small_sort.c  sort_utils.c big_sort.c    utils.c
SRCS_B= bonus.c ft_error_bonus.c get_next_line.c sort_utils_bonus.c utils_bonus.c

CFLAGS= -Wall -Wextra -Werror -g

OBJS :=$(SRCS:.c=.o)
OBJS_B:=$(SRCS_B:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	(cd libft; Make all;)
	gcc $(CFLAGS) libft/libft.a $^ -o $@

bonus: $(OBJS_B)
	(cd libft; Make all;)
	gcc $(CFLAGS) libft/libft.a $^ -o test

%.o: %.c push_swap.h
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) bonus

re: fclean all

