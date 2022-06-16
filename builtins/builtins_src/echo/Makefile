NAME = ../../bin/echo
SRC = echo.c
SRC_UTILS = ../../../src/utils/*.c

LIB = ../../../libft/libft.a
LDIR = ../../../libft

INCL = ../../../src/minishell.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(INCL) $(SRC_UTILS)
	$(CC) $(CFLAGS) $(SRC) $(SRC_UTILS) $(LIB) -o $(NAME)

$(LIB): $(LDIR)
	make -C $(LDIR)

clean:
	make -C $(LDIR) clean

fclean: clean
	make -C $(LDIR) fclean
	rm -f $(NAME)

re: fclean all