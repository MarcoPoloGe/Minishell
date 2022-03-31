NAME = Minishell

SRC = history.c

LIB =  ./my_libft/libft.a
LDIR = ./my_libft

INCL =
IDIR =

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lreadline -L /Users/mbelarbi/.brew/Cellar/readline/8.1.2/lib   -I /Users/mbelarbi/.brew/Cellar/readline/8.1.2/include

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
