# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoraes- <jmoraes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 10:14:58 by m4rch             #+#    #+#              #
#    Updated: 2023/12/14 21:51:19 by jmoraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAKEFILE TEMPLATE - M4RCH

# CAPS CAPS => Accept inline suggestions
# := # Assign a value to a variable
# ?= # Conditional variable assigment - assign if variable isn't yet defined.
# $@ # The file name of the target of the rule
# $< # The name of the first prerequisite
# # MAKEFILE TEMPLATE - M4RCH

BLACK		:=	"\033[1;30m"
RED			:=	"\033[1;31m"
GREEN		:=	"\033[1;32m"
CYAN		:=	"\033[1;35m"
BLUE		:=	"\033[1;36m"
WHITE		:=	"\033[1;37m"
EOC			:=	"\033[0;0m"

MAX_INT		=	2147483647
MIN_INT		=	-2147483648

# PROGRAM
NAME		=	minishell

#BIBLIOTHEQUES STATIQUES
NAME		?=	minishell.a
NAME_LIBFT	:=	libft.a
NAME_GNL	:=	get_next_line.a
# NAME_PRINTF	:=	libftprintf.a

# EXECUTABLES
CC			?= clang
AR			:=	ar rcs
RM			:=	rm -rf

# FLAGS
CFLAGS		?= -g -Wall -Wextra -Werror
IFLAGS		:= -I./header -I./libft #-I./printf
LDFLAGS		:= -L./libft
LDLIBS		:= -lft -lreadline

#PATHS
SRC_PATH	:= src
OBJ_PATH	:= bin
INC_PATH	:= header
UTILS_PATH	:= utils
LIBFT_PATH	:= libft

LIBFT_OBJ	:= $(addprefix $(LIBFT_PATH)/, bin/*.o)

#FILES
MAIN		= main.c minishell.c handle_heredoc.c split_commands.c handle_heredoc_utils.c
ERROR		= error.c error2.c input_error.c
EXEC		= exec_builtin.c exec_multi_cmds.c exec_one_cmd.c get_path.c \
				multi_cmds_utils.c pipes.c split_args.c wait.c \
				exec_external.c one_cmd_utils.c handle_execute_one_command.c
EXPANDS		= variables_utils.c
HEADER		= minishell.h clib.h macro.h structure.h prototyping.h
LIBFT_A		= ./libft/libft.a
PROMPT		= prompt.c
REDIR		= redirect_heredoc.c redirect_input.c redirect_output.c redirect_utils.c
SIGNALS		= 
SYNTAX		= syntax.c syntax_utils.c

JM_UTILS	= array_utils.c expand_exit_status.c expand_variables.c fd_utils.c \
				ft_atoll.c get_label_name.c handle_expansions.c list_utils.c \
				quotes_utils.c signals.c str_checkers.c str_utils.c builtins_utils.c

JM_BUILTINS	= cd.c echo.c env.c pwd.c export.c unset.c exit.c \
				export_key.c export_utils1.c export_utils2.c

JM_MSENV	= msenv_cleanup.c msenv_ini.c msenv_load.c msenv_minload.c \
				msenv_shlvlup.c msenv_utils.c msenv_utils2.c msenv_get.c \
				msenv_updates.c msenv_convert.c

JM_UTILS2	= ft_str_equal.c ft_variables_utils.c ft_error.c

JM_HEADER	= builtins.h clib.h errmsg.h error.h exits.handle_expansions

MS_JM		= $(JM_BUILTINS) $(JM_MSENV) $(JM_UTILS) $(JM_UTILS2)

VPATH		= main ms_jm/builtins_2 ms_jm/msenv ms_jm/utils ms_jm/utils2 \
				ms_jm/error exec expands prompt redir syntax 
				
INCLUDE		= $(IFLAGS)

SRC_FILES	:=	$(MAIN) $(MS_JM) $(BUILTINS) $(ERROR) $(EXEC) $(EXPANDS) \
				$(MSENV) $(PROMPT) $(REDIR) $(SIGNALS) $(SYNTAX) $(UTILS)
OBJ_FILES	:= $(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))

# REGLES
all:	$(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LDLIBS) $(LDFLAGS)
	@echo $(GREEN)"[OK] "$(EOC)$(CYAN)"$(NAME) compiled"$(EOC)

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(LIBFT_A):
	@make -sC ./libft

clean:
	@make -sC ./libft clean
	@$(RM) $(OBJ_PATH)

fclean: clean
	@make -sC ./libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
