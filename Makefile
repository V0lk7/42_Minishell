# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 16:36:26 by kramjatt          #+#    #+#              #
#    Updated: 2023/03/17 23:23:21 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	minishell

MAKEFLAGS	+=	--no-print-directory

###############################################################################

LIBS 		=	ft

LIBS_TARGET =	src/libft/libft.a

INCLUDES	=	src/libft/include

###############################################################################

SRC_DIR 	=	src

OBJ_DIR 	=	.obj

SRCS		:= 	built_in/builts.c		built_in/cd.c		\
				built_in/echo.c			built_in/env.c		\
				built_in/exit.c			built_in/export.c	\
				built_in/export_utils.c built_in/pwd.c		\
				built_in/unset.c	\

SRCS		+=	process/history.c		process/main.c		\
				process/init_f.c		\

SRCS		+=	clear/free_exit.c		\

SRCS		+=	parsing/valid_quotes.c		parsing/syntax_is_valid.c	\
				parsing/syntax_is_valid2.c 	parsing/syntax_management.c	\
				parsing/make_cmdline.c	\

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

OBJS 		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

###############################################################################

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -g -gdwarf-2

CPPFLAGS	=	-MMD -MP $(addprefix -I,$(INCLUDES))

LDFLAGS		=	$(addprefix -L,$(dir $(LIBS_TARGET)))

LDLIBS		=	$(addprefix -l,$(LIBS))

DIRDUP 		= 	mkdir -p $(@D)

###############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -lreadline -o $(NAME)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(dir $@)

$(OBJ_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS) test.mk


clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C src/libft
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
	@make fclean -C src/libft
.PHONY: fclean

re: fclean all
.PHONY: re
