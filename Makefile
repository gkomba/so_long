# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 17:24:03 by gkomba            #+#    #+#              #
#    Updated: 2024/08/15 08:40:36 by gkomba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = srcs/so_long.c\
		srcs/init.c\
		srcs/build_map.c\
		srcs/map_validations.c\
		srcs/map_validations_utils1.c\
		srcs/map_validations_utils2.c\
		srcs/flood_fill.c\
		srcs/render_map.c\
		srcs/events.c\
		srcs/events_utils.c\
		srcs/game_validations.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
CC = cc
CFALGS = -Wall -Wextra -Wall
MLX = -I./minilibx-linux -L./minilibx-linux -lmlx -L/usr/include/../lib -lXext -lX11 -lm
RM = rm -f
LIBFT = libft
MLXD = minilibx-linux
all: $(NAME)
$(NAME): $(OBJS)
		make -C $(LIBFT)
		$(CC) ${CFALGS} -o $(NAME) $(OBJS) $(LIBFT)/libft.a $(MLX)
		
clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
		make fclean -C $(LIBFT)
		$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re

.PHONY: all clean fclean re
