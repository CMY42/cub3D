# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 16:04:14 by cmansey           #+#    #+#              #
#    Updated: 2023/10/31 17:52:15 by cmansey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC = cub3D.c window.c image.c color.c hooks.c loop.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -f
CCFLAGS = -Wextra -Wall -Werror

LIBFT = libft

all: $(NAME)

$(NAME):$(OBJ)
	@make -C $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ) -Llibft -lft -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT)


fclean: clean
	$(RM) $(NAME)
	@$(RM) -f $(LIBFT)/libft.a


mlx:
	@$(MAKE) re -C mlx/

re: fclean all

.PHONY:	all clean fclean re libft ft_printf
