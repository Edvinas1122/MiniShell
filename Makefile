# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cthien-h <cthien-h@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:05:55 by emomkus           #+#    #+#              #
#    Updated: 2022/03/25 17:50:19 by cthien-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = minishell

#Library files#
LIBFT_FILES = libft.a
LIBFT_DIR = src/libs/libft/
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_FILES))

#Executor files#
EXECUTOR_FILES = forking.c
EXECUTOR_DIR = src/executor/
EXECUTOR = $(addprefix $(EXECUTOR_DIR),$(EXECUTOR_FILES))
EXECUTOR_OBJ = $(EXECUTOR_FILES:.c=.o)
EXECUTOR_TEST_FILES = print_fd.c argv_manage.c read_fd.c
EXECUTOR_TEST_DIR = src/executor/test/
EXECUTOR_TEST = $(addprefix $(EXECUTOR_TEST_DIR),$(EXECUTOR_TEST_FILES))
EXECUTOR_TEST_OBJ = $(EXECUTOR_TEST_FILES:.c=.o)
EXECUTOR_TEST_NAME = executor-test

#Parser files#
# PARSER_SRC = parser.c
# PARSER_DIR = src/parser/
# PARSER = $(addprefix $(PARSER_DIR),$(PARSER_SRC))
# PARSER_OBJ = $(PARSER_SRC:.c=.o)
# PARSER_TEST_SRC = parser_main.c
# PARSER_TEST_DIR = src/parser/test/
# PARSER_TEST = $(addprefix $(PARSER_TEST_DIR),$(PARSER_TEST_SRC))
# PARSER_TEST_OBJ = $(PARSER_TEST_SRC:.c=.o)
# PARSER_TEST_NAME = parser-test

#Constructor files#
CONSTR_SRC = constructor.c
CONSTR_DIR = src/
CONSTR = $(addprefix $(CONSTR_DIR),$(CONSTR_SRC))
CONSTR_OBJ = $(CONSTR_SRC:.c=.o)

#Lexer files#
LEXER_SRC = lexer.c
LEXER_DIR = src/parser/
LEXER = $(addprefix $(LEXER_DIR),$(LEXER_SRC))
LEXER_OBJ = $(LEXER_SRC:.c=.o)
LEXER_TEST_SRC = lexer_test.c
LEXER_TEST_DIR = src/parser/test/
LEXER_TEST = $(addprefix $(LEXER_TEST_DIR),$(LEXER_TEST_SRC))
LEXER_TEST_OBJ = $(LEXER_TEST_SRC:.c=.o)
LEXER_TEST_NAME = lexer-test

#Utils files#
UTILS_SRC = ft_isspace.c str_remove_char_at.c
UTILS_DIR = src/utils/
UTILS = $(addprefix $(UTILS_DIR),$(UTILS_SRC))
UTILS_OBJ = $(UTILS_SRC:.c=.o)

.PHONY: all clean fclean re executor parser

#Main Compilation#
all: $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

#Executor test compilation#
executor: $(EXECUTOR_OBJ) $(EXECUTOR_TEST_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(EXECUTOR_OBJ) $(EXECUTOR_TEST_OBJ) $(LIBFT) -o $(EXECUTOR_TEST_NAME)

$(EXECUTOR_OBJ): $(EXECUTOR)
	$(CC) $(FLAGS) -c $(EXECUTOR)

$(EXECUTOR_TEST_OBJ): $(EXECUTOR_TEST)
	$(CC) $(FLAGS) -c $(EXECUTOR_TEST)

#Parser test compile#
# parser:  $(PARSER_OBJ) $(PARSER_TEST_OBJ) $(LIBFT)
# 	$(CC) $(FLAGS) $(PARSER_OBJ) $(PARSER_TEST_OBJ) $(LIBFT) -o $(PARSER_TEST_NAME)

# $(PARSER_OBJ): $(PARSER)
# 	$(CC) $(FLAGS) -c $(PARSER)

# $(PARSER_TEST_OBJ): $(PARSER_TEST)
# 	$(CC) $(FLAGS) -c $(PARSER_TEST)

#Lexer test compile#
lexer:  $(LEXER_OBJ) $(LEXER_TEST_OBJ) $(UTILS_OBJ) $(CONSTR_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(LEXER_OBJ) $(LEXER_TEST_OBJ) $(UTILS_OBJ) $(CONSTR_OBJ) $(LIBFT) -o $(LEXER_TEST_NAME) -lreadline

$(LEXER_OBJ): $(LEXER)
	$(CC) $(FLAGS) -c $(LEXER)

$(LEXER_TEST_OBJ): $(LEXER_TEST)
	$(CC) $(FLAGS) -c $(LEXER_TEST)

#Utils compile#
$(UTILS_OBJ): $(UTILS)
	$(CC) $(FLAGS) -c $(UTILS)

#Utils compile#
$(CONSTR_OBJ): $(CONSTR)
	$(CC) $(FLAGS) -c $(CONSTR)

#Library#
$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(EXECUTOR_OBJ) $(EXECUTOR_TEST_OBJ) $(LEXER_OBJ) $(LEXER_TEST_OBJ) $(UTILS_OBJ) $(CONSTR_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(EXECUTOR_TEST_NAME) $(LEXER_TEST_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
