# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 13:40:58 by ddecourt          #+#    #+#              #
#    Updated: 2022/05/24 13:40:20 by bben-yaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/cub3d.c \
			srcs/parsing/check_map.c \
			srcs/parsing/parsing.c \
			srcs/parsing/check_texture.c \
			srcs/parsing/check_texture_utils.c \
			srcs/parsing/check_color.c \
			srcs/parsing/store_map.c \
			srcs/parsing/store_params.c \
			srcs/parsing/store_params_utils.c \
			srcs/parsing/init_env.c \
			srcs/parsing/len_map.c \
			srcs/parsing/alloc_map.c \
			srcs/parsing/alloc_map2.c \
			srcs/win_utils.c \
			srcs/raycasting.c \
			srcs/raycasting_utils.c \
			srcs/get_next_line/get_next_line.c \
			srcs/get_next_line/get_next_line_utils.c \
			srcs/mlx_utils.c


OBJS	= ${SRCS:.c=.o}

NAME	= Cub3D

HEADER	= mlx/mlx.h 

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g3

RM = rm -f

.c .o:
	$(CC) $(CFLAGS) -Imlx -Lmlx -lmlx -O3 -c $< -o $@ 

$(NAME): $(OBJS)
		make -C libft
		make -C mlx
		$(CC) $(CFLAGS) $(OBJS)  -Imlx -Lmlx -lmlx -I -L./libft/ -Imlx -lXext -lX11 -lm ./libft/libft.a -o ${NAME}

all:	${NAME}

clean:
		make clean -C libft
		make clean -C mlx
		${RM} ${OBJS}

fclean: clean	
		make fclean -C libft
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
