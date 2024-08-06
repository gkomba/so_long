# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 17:24:03 by gkomba            #+#    #+#              #
#    Updated: 2024/08/06 17:31:38 by gkomba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
CC = CC
CFALGS = -Wall -Wextra -Wall
MLX = 
LIBFT = libft

all: $(NAME)

$(NAME): $(OBJS)
		make -s -C $(LIBFT)
		$(CC) $(CFALGS) -o $(NAME) $(LIBFT)/libft.a
clean:
	make clean -s -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT)
		$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re