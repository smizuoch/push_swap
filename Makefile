# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 15:43:29 by smizuoch          #+#    #+#              #
#    Updated: 2023/08/16 13:46:47 by smizuoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c algo.c chack_same.c push.c reverse_rotate.c rotate.c sort6.c swap.c quick_sort.c sort100_500.c ps_atoi.c ps_split.c error_exit.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
