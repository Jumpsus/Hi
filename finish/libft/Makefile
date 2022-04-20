# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pratanac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 20:59:54 by pratanac          #+#    #+#              #
#    Updated: 2022/02/23 14:44:11 by pratanac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_memset.c	\
	ft_bzero.c	\
	ft_memcpy.c	\
	ft_memmove.c 	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_strlen.c	\
	ft_isalpha.c 	\
	ft_isdigit.c	\
	ft_isalnum.c	\
	ft_isascii.c	\
	ft_isprint.c	\
	ft_toupper.c	\
	ft_tolower.c	\
	ft_strchr.c	\
	ft_striteri.c	\
	ft_strrchr.c	\
	ft_strncmp.c	\
	ft_strlcpy.c	\
	ft_strlcat.c	\
	ft_strnstr.c	\
	ft_atoi.c	\
	ft_calloc.c	\
	ft_strdup.c	\
	ft_substr.c	\
	ft_strjoin.c 	\
	ft_strtrim.c	\
	ft_split.c	\
	ft_itoa.c	\
	ft_strmapi.c	\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_clr_atoi.c

NAME = libft.a

OBJS_DIR = objs/

OBJS = $(SRCS:.c=.o)

OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = clang

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	
	@echo "Compiling: $<"
	
	@clang $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	
	@ar rc $(NAME) $(OBJECTS_PREFIXED)
	
	@echo "Libft Done !"


all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)


fclean:	clean
	
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re
