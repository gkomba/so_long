# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 17:24:03 by gkomba            #+#    #+#              #
#    Updated: 2024/08/07 15:59:05 by gkomba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = srcs/so_long.c\
		srcs/init.c\
		srcs/map_validations.c\
		srcs/map_validations_utils1.c\
		srcs/map_validations_utils2.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
CC = cc
CFALGS = -Wall -Wextra -Wall
MLX = -I./minilibx-linux -L./minilibx-linux -lmlx -L/usr/include/../lib -lXext -lX11 -lm
RM = rm -f
LIBFT = libft

all: $(NAME)

$(NAME): $(OBJS)
		make -s -C $(LIBFT)
		$(CC) -o $(NAME) $(OBJS) $(LIBFT)/libft.a
		make clean

clean:
	make clean -s -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT)
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re