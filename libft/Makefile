# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 16:36:26 by kramjatt          #+#    #+#              #
#    Updated: 2023/02/24 20:24:07 by kramjatt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = src
OBJ_DIR = .obj

SRC = 	src/count_args_2d.c \
		src/cpy_array2d.c \
		src/free_array2d.c \
		src/ft_calloc.c \
		src/ft_memset.c \
		src/ft_split.c \
		src/ft_strcpy.c \
		src/ft_strcmp.c \
		src/ft_strncmp.c \
		src/ft_strjoin.c \
		src/ft_strlen.c \
		src/ft_strrchr.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/get_next_line.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -gdwarf-2

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
