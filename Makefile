NAME = minishell

SRC = main.c display.c lexer.c parser.c executor.c expander.c prompt.c utils.c
SRC_PARSER_UTILS = get_cmd_path.c check_env.c init_struct.c extract_fd.c get_redir_path.c
SRC_EXPANDER_UTILS = pipe.c

SRC_PATH := $(foreach wrd,$(SRC),./src/$(wrd)) $(foreach wrd,$(SRC_EXPANDER_UTILS),src/expander_utils/$(wrd)) $(foreach wrd,$(SRC_PARSER_UTILS),src/parser_utils/$(wrd))

LIB = ./libft/libft.a
LDIR = ./libft

INCL = src/minishell.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror  -lreadline -L ./readline/8.1.2/lib -I ./readline/8.1.2/include #-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC_PATH) $(LIB) $(INCL)
	$(CC) $(CFLAGS) $(SRC_PATH) $(LIB) -o $(NAME)

$(LIB): $(LDIR)
	make -C $(LDIR)

clean:
	make -C $(LDIR) clean

fclean: clean
	make -C $(LDIR) fclean
	rm -f $(NAME)

re: fclean all

test: $(SRC_PATH) $(LIB) $(INCL)
	$(CC) -lreadline -L ./readline/8.1.2/lib -I ./readline/8.1.2/include $(SRC_PATH) $(LIB) -o $(NAME)