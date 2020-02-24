# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pelease <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 14:45:15 by pelease           #+#    #+#              #
#    Updated: 2020/01/22 14:55:04 by pelease          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ../libft

DIR_S = sources

DIR_O = tmp

INCLUDE = include

SOURCE = ft_printf.c \
		  input_info.c \
		  type_execution.c \
		  type_execution_part2.c \
		  all_for_int_uint.c \
		  ft_itoa_printf.c \
		  show_int_uint.c \
		  ft_uitoa_printf.c \
		  conversion.c \
		  all_for_octa.c \
		  show_octa.c \
		  all_for_hex.c \
		  show_hex.c \
		  all_for_pointer_and_percent.c \
		  show_pointer.c \
		  all_for_char_string.c \
		  bonus_functions.c \
		  all_for_float.c \
		  show_float.c \
		  show_float_part2.c

SRC = $(addprefix $(DIR_S)/,$(SOURCE))

OBJ = $(addprefix $(DIR_O)/,$(SOURCE:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp ../libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
