NAME = minishell

SRC = main.c display.c lexer.c parser.c executor.c expander.c get_cmd_path.c

LIB = ./libft/libft.a
LDIR = ./libft

INCL = minishell.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror  -lreadline -L ./readline/8.1.2/lib -I ./readline/8.1.2/include #-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(INCL)
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

$(LIB): $(LDIR)
	make -C $(LDIR)

clean:
	make -C $(LDIR) clean

fclean: clean
	make -C $(LDIR) fclean
	rm -f $(NAME)

re: fclean all