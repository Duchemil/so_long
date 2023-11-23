# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:31:42 by lduchemi          #+#    #+#              #
#    Updated: 2023/11/23 17:29:27 by lduchemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc -Wall -Wextra -Werror -g3
OBJS = main.c ft_convert.c ft_convert2.c ft_check.c ft_winnable.c ft_print.c ft_movement.c
INCLUDES = -I/usr/include -Imlx

%.o: %.c
	$(CC) -Imlx -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(OBJS) mlx/libmlx.a -lXext -lX11 -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
