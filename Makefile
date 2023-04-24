# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 16:36:26 by kramjatt          #+#    #+#              #
#    Updated: 2023/04/24 17:20:41 by jduval           ###   ########.fr        #
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

SRCS		:= 	built_in/builts.c				built_in/cd.c						\
				built_in/echo.c					built_in/env.c						\
				built_in/exit.c					built_in/export.c					\
				built_in/export_utils.c 		built_in/pwd.c						\
				built_in/unset.c													\

SRCS		+=	clear/free_exit.c				clear/free_lst.c					\
				clear/free_in_fork.c												\

SRCS		+=	parsing/valid_quotes.c			parsing/syntax_is_valid.c			\
				parsing/syntax_is_valid2.c 		parsing/syntax_management.c			\
				parsing/simplify_user_input.c	parsing/make_cmdline.c				\
				parsing/make_data.c				parsing/make_path.c					\
				parsing/command_control.c		parsing/quote_removal.c				\
				parsing/dollar_in_quote.c		parsing/expansion_management.c		\
				parsing/divide_words.c			parsing/expand_words_splitting.c	\
				parsing/shapeshift_str.c	\

SRCS		+=	process/history.c				process/main.c						\
				process/init_f.c				process/management_minishell.c		\
				process/normal_execution.c		process/duplicate_functions.c		\
				process/pipeline_execution.c	process/here_doc.c					\
				process/signals.c				process/utils_pipeline.c			\

SRCS		+=	utils/command_data_utils.c											\
				utils/data_by_line_utils.c											\
				utils/errors.c														\
				utils/expansion.c													\
				utils/expansion_utils.c												\
				utils/hdoc_utils.c													\
				utils/list_utils.c													\
				utils/list_utils2.c													\
				utils/list_expand.c													\
				utils/make_command_utils.c											\
				utils/replace_expansion.c											\
				utils/split_by_pipe_utils.c											\
				utils/split_by_str_utils.c											\
				utils/split_by_str.c												\

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
