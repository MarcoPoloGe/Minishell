NAME = ../bin/echo
SRC = echo.c

LIB = ../../libft/libft.a
LDIR = ../../libft

INCL = ../../src/minishell.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(INCL) $(SRC_UTILS)
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

$(LIB): $(LDIR)
	make -C $(LDIR)

clean:
	make -C $(LDIR) clean

fclean: clean
	make -C $(LDIR) fclean
	rm -f $(NAME)

re: fclean all