# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:05:55 by emomkus           #+#    #+#              #
#    Updated: 2022/04/11 23:18:12 by cthien-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -I $(HOME)/goinfre/.brew/opt/readline/include/
NAME = minishell

SRC = main.c
DIR = src/
FILES = $(addprefix $(DIR),$(SRC))
OBJ = $(SRC:.c=.o)

#Library files#
LIBFT_FILES = libft.a
LIBFT_DIR = src/libs/libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))

#Executor files#
EXECUTOR_FILES = executor.c accessor_con.c fork_exec.c builtin_executor.c
EXECUTOR_DIR = src/executor/
EXECUTOR = $(addprefix $(EXECUTOR_DIR),$(EXECUTOR_FILES))
EXECUTOR_OBJ = $(EXECUTOR_FILES:.c=.o)

#Parser files#
PARSER_SRC = parser.c env_resolver.c lexer.c command_splitter.c
PARSER_DIR = src/parser/
PARSER = $(addprefix $(PARSER_DIR),$(PARSER_SRC))
PARSER_OBJ = $(PARSER_SRC:.c=.o)

#Parser test files#
PARSER_TEST_SRC = parser_test.c
PARSER_TEST_DIR = src/parser/test/
PARSER_TEST = $(addprefix $(PARSER_TEST_DIR),$(PARSER_TEST_SRC))
PARSER_TEST_OBJ = $(PARSER_TEST_SRC:.c=.o)
PARSER_TEST_NAME = parser-test.out

#Constructor files#
CONSTR_SRC = constructor.c deconstructor.c
CONSTR_DIR = src/constructor/
CONSTR = $(addprefix $(CONSTR_DIR),$(CONSTR_SRC))
CONSTR_OBJ = $(CONSTR_SRC:.c=.o)

#Builtin files#
BUILTIN_SRC = echo.c unset.c env.c exit.c cd.c export.c pwd.c
BUILTIN_DIR = src/builtin/
BUILTIN = $(addprefix $(BUILTIN_DIR),$(BUILTIN_SRC))
BUILTIN_OBJ = $(BUILTIN_SRC:.c=.o)

#Utils files#
UTILS_SRC = ft_isspace.c str_remove_char_at.c str_replace_str_at.c find_list.c \
			is_meta_char.c char_array_len.c str_join_space.c free_array.c \
			is_str_redir.c get_env_value.c dup2_and_close.c signals.c is_valid_env.c \
			ft_isnbr.c change_directory.c get_cwd.c find_delete_list.c export_print_alone.c
UTILS_DIR = src/utils/
UTILS = $(addprefix $(UTILS_DIR),$(UTILS_SRC))
UTILS_OBJ = $(UTILS_SRC:.c=.o)

.PHONY: all clean fclean re executor parser

#Main Compilation#
all: $(CONSTR_OBJ) $(PARSER_OBJ) $(UTILS_OBJ) $(BUILTIN_OBJ) $(EXECUTOR_OBJ) $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(CONSTR_OBJ) $(PARSER_OBJ) $(UTILS_OBJ) $(BUILTIN_OBJ) $(EXECUTOR_OBJ) $(OBJ) $(LIBFT) -o $(NAME) -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline

$(OBJ): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

$(EXECUTOR_OBJ): $(EXECUTOR)
	$(CC) $(FLAGS) -c $(EXECUTOR)

#Parser test compile#
parser:  $(PARSER_OBJ) $(PARSER_TEST_OBJ) $(UTILS_OBJ) $(CONSTR_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(PARSER_OBJ) $(PARSER_TEST_OBJ) $(UTILS_OBJ) $(CONSTR_OBJ) $(LIBFT) -o $(PARSER_TEST_NAME) -lreadline

$(PARSER_OBJ): $(PARSER)
	$(CC) $(FLAGS) -c $(PARSER)

$(PARSER_TEST_OBJ): $(PARSER_TEST)
	$(CC) $(FLAGS) -c $(PARSER_TEST)

#Utils compile#
$(UTILS_OBJ): $(UTILS)
	$(CC) $(FLAGS) -c $(UTILS)

#Constructor compile#
$(CONSTR_OBJ): $(CONSTR)
	$(CC) $(FLAGS) -c $(CONSTR)

#Builtin compile#
$(BUILTIN_OBJ): $(BUILTIN)
	$(CC) $(FLAGS) -c $(BUILTIN)

#Library#
$(LIBFT):
	make bonus -C $(LIBFT_DIR)

clean:
	rm -f $(EXECUTOR_OBJ) $(EXECUTOR_TEST_OBJ) $(PARSER_OBJ) $(PARSER_TEST_OBJ) $(UTILS_OBJ) $(CONSTR_OBJ) $(BUILTIN_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf *.dSYM
	rm -f $(EXECUTOR_TEST_NAME) $(PARSER_TEST_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
