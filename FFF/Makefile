NAME = FDF

SRC = 	src/0_get_next_line.c	\
	src/1_set_utils.c	\
	src/2_set_utils.c	\
	src/3_convert_posit.c	\
	src/4_adjust_matrix.c	\
	src/5_drawing.c		\
	src/7_bonus_stuff.c

MAN = src/6_event.c

EXTRA = src/6_event_bonus.c

FLAG = -Wall -Wextra -Werror

LIBFT = libft.a

all : $(LIBFT) $(NAME) bonus

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT)
	@gcc $(FLAG) -I header $(SRC) $(MAN) src/FDF.c libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o fdf
	@echo "FDF is finished !!"

bonus : $(LIBFT)
	@gcc $(FLAG) -I header $(SRC) $(EXTRA) src/FDF_bonus.c libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o fdf_bonus
	@echo "FDF bonus part is finished !!"

clean :
	@make -C libft clean
	@echo "cleaning is finished !!"

fclean :
	@make -C libft fclean
	@rm -rf fdf
	@rm -rf fdf_bonus
	@echo "fcleaning is finished !!"

re : fclean all

.PHONY: all $(LIBFT) $(NAME) bonus clean fclean re
