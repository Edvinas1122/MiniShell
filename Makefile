# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:05:55 by emomkus           #+#    #+#              #
#    Updated: 2022/03/21 21:28:27 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = MiniShell

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
NAME_EXE = executor

#Syntax lexical interpretor#

#Main Compilation#
all: $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ): $(FILES)
	$(CC) $(FLAGS) -c $(FILES)

#Executor test compilation#
executor: $(EXECUTOR_OBJ) $(EXECUTOR_TEST_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(EXECUTOR_OBJ) $(EXECUTOR_TEST_OBJ) $(LIBFT) -o $(NAME_EXE)
	rm $(EXECUTOR_OBJ)
	rm $(EXECUTOR_TEST_OBJ)

$(EXECUTOR_OBJ): $(EXECUTOR)
	$(CC) $(FLAGS) -c $(EXECUTOR)

$(EXECUTOR_TEST_OBJ): $(EXECUTOR_TEST)
	$(CC) $(FLAGS) -c $(EXECUTOR_TEST)

#Library#
$(LIBFT):
	make -C $(LIBFT_DIR)