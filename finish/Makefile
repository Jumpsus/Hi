# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pratanac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:24:34 by pratanac          #+#    #+#              #
#    Updated: 2022/04/18 21:00:43 by pratanac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

SRC = 	src/0_get_next_line.c	\
	src/1_set_utils.c	\
	src/2_set_utils.c	\
	src/3_convert_posit.c	\
	src/4_adjust_matrix.c	\
	src/6_event.c		\
	src/7_bonus_stuff.c	\
	src/9_drawing.c		\
	src/8_check_stuff.c	\

MAN = src/6_event.c

EXTRA = src/6_event_bonus.c

FLAG = -Wall -Wextra -Werror

LIBFT = libft.a

all : $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT)
	@gcc $(FLAG) -I header $(SRC)src/FDF.c libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o fdf
	@echo "FDF is finished !!"

clean :
	@make -C libft clean
	@echo "cleaning is finished !!"

fclean :
	@make -C libft fclean
	@rm -rf fdf
	@rm -rf fdf_bonus
	@echo "fcleaning is finished !!"

re : fclean all

.PHONY: all $(LIBFT) $(NAME) clean fclean re
