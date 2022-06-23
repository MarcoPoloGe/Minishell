NAME = minishell

SRC = main.c display.c lexer.c parser.c executor.c expander.c prompt.c signals.c
SRC_LEXER_UTILS = put_tokens_in_order.c build_tokens_tab.c cmd_tokens_in_order.c replace_env_var.c
SRC_PARSER_UTILS = get_cmd_path.c check_env.c init_struct.c extract_fd.c get_redir_path.c
SRC_EXPANDER_UTILS = pipe.c
SRC_UTILS = free_error.c meta.c redir.c env_modify.c env_read.c builtin.c
SRC_SPECIAL_BUILTINS = cd.c exit.c export.c unset.c cd_utils.c

SRC_PATH := $(foreach wrd,$(SRC),./src/$(wrd))\
			$(foreach wrd,$(SRC_EXPANDER_UTILS),src/expander_utils/$(wrd))\
			$(foreach wrd,$(SRC_PARSER_UTILS),src/parser_utils/$(wrd))\
			$(foreach wrd,$(SRC_LEXER_UTILS),src/lexer_utils/$(wrd))\
			$(foreach wrd,$(SRC_UTILS),src/utils/$(wrd))\
			$(foreach wrd,$(SRC_SPECIAL_BUILTINS),src/special_builtins/$(wrd))

LIB = ./libft/libft.a
LIB_DIR = ./libft

BUILTINS = ./builtins/bin
BUILTINS_DIR = ./builtins

REDIR = ./redir/bin
REDIR_DIR = ./redir

INCL = src/minishell.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -L$(HOME)/.brew/opt/readline/lib -I$(HOME)/.brew/opt/readline/include #-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC_PATH) $(BUILTINS) $(REDIR) $(LIB) $(INCL)
	$(CC) $(CFLAGS) $(SRC_PATH) $(LIB) -o $(NAME)

$(BUILTINS): $(BUILTINS_DIR)
	make -C $(BUILTINS_DIR)

$(REDIR): $(REDIR_DIR)
	make -C $(REDIR_DIR)

$(LIB): $(LIB_DIR)
	make -C $(LIB_DIR)

clean:
	make -C $(LIB_DIR) clean
	make -C $(BUILTINS_DIR) clean
	make -C $(REDIR_DIR) clean

fclean: clean
	make -C $(LIB_DIR) fclean
	make -C $(BUILTINS_DIR) fclean
	make -C $(REDIR_DIR) fclean
	rm -f ./config_files/env.txt
	rm -f $(NAME)

re: fclean all

test: $(SRC_PATH) $(LIB) $(INCL)
	$(CC) -lreadline -L ./readline/8.1.2/lib -I ./readline/8.1.2/include $(SRC_PATH) $(LIB) -o $(NAME)