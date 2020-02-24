# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pelease <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/05 15:43:22 by pelease           #+#    #+#              #
#    Updated: 2019/09/30 21:31:46 by pelease          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

DIR_S = src

DIR_O = tmp

INCLUDE = ./include

SOURCE = ft_memset.c ft_strdup.c ft_strlen.c ft_memmove.c ft_strmap.c \
		ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_strmapi.c \
		ft_memcmp.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strequ.c \
		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnequ.c \
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_strsub.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c \
		ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_itoa.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_strsplit.c ft_lstiter.c ft_lstmap.c ft_swap.c \
		ft_strupcase.c ft_strlowcase.c ft_isspace.c ft_abs.c get_next_line.c

SRC = $(addprefix $(DIR_S)/,$(SOURCE))

OBJ = $(addprefix $(DIR_O)/,$(SOURCE:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
