SRC = main.c$
FILES = $(addprefix $(DIR),$(SRC))$
OBJ = $(SRC:.c=.o)$
PARSER_SRC = parser.c env_resolver.c lexer.c command_splitter.c$
PARSER = $(addprefix $(PARSER_DIR),$(PARSER_SRC))$
PARSER_OBJ = $(PARSER_SRC:.c=.o)$
PARSER_TEST_SRC = parser_test.c$
PARSER_TEST = $(addprefix $(PARSER_TEST_DIR),$(PARSER_TEST_SRC))$
PARSER_TEST_OBJ = $(PARSER_TEST_SRC:.c=.o)$
CONSTR_SRC = constructor.c deconstructor.c$
CONSTR = $(addprefix $(CONSTR_DIR),$(CONSTR_SRC))$
CONSTR_OBJ = $(CONSTR_SRC:.c=.o)$
BUILTIN_SRC = echo.c unset.c env.c exit.c cd.c export.c pwd.c$
BUILTIN = $(addprefix $(BUILTIN_DIR),$(BUILTIN_SRC))$
BUILTIN_OBJ = $(BUILTIN_SRC:.c=.o)$
UTILS_SRC = ft_isspace.c str_remove_char_at.c str_replace_str_at.c find_list.c \$
UTILS = $(addprefix $(UTILS_DIR),$(UTILS_SRC))$
UTILS_OBJ = $(UTILS_SRC:.c=.o)$
hello world$
hello abc$
