# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 17:24:03 by gkomba            #+#    #+#              #
#    Updated: 2024/08/09 06:57:44 by gkomba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = srcs/so_long.c\
		srcs/init.c\
		srcs/map_validations.c\
		srcs/map_validations_utils1.c\
		srcs/map_validations_utils2.c\
		srcs/flood_fill.c\
		srcs/render_map.c

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
		$(CC) -o $(NAME) $(OBJS) $(LIBFT)/libft.a $(MLX)
		

clean:
	make clean -s -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT)
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re