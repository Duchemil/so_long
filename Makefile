# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduchemi <lduchemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:31:42 by lduchemi          #+#    #+#              #
#    Updated: 2023/11/28 15:41:21 by lduchemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc -Wall -Wextra -Werror -g3
OBJS = ./core/main.c ./core/ft_convert.c ./core/ft_convert2.c ./core/ft_check.c ./core/ft_winnable.c ./core/ft_print.c ./core/ft_movement.c
OBJBONUS = ./bonus/main.c ./bonus/ft_convert.c ./bonus/ft_convert2.c ./bonus/ft_check.c ./bonus/ft_winnable.c ./bonus/ft_print.c ./bonus/ft_movement.c ./bonus/ft_itoa.c
INCLUDES = -I/usr/include -Imlx

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) ./mlx/libmlx.a -lXext -lX11 -o $(NAME)

bonus : $(OBJBONUS)
	$(CC) $(OBJBONUS) ./mlx/libmlx.a -lXext -lX11 -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

