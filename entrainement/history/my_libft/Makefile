NAME = libft.a

SRC_GET_NEXT_LINE = get_next_line/get_next_line.c

SRC_PRINTF = printf/ft_printf.c printf/printf_utils/ft_itoa_base_16.c printf/printf_utils/ft_print_pointer_len.c printf/printf_utils/ft_putchar_len.c printf/printf_utils/ft_putnbr_len.c printf/printf_utils/ft_putstr_len.c printf/printf_utils/ft_puthexa_len.c

SRC_LIBFT42 = libft42/ft_isalpha.c libft42/ft_memchr.c libft42/ft_putchar_fd.c libft42/ft_strdup.c libft42/ft_strlen.c libft42/ft_tolower.c libft42/ft_atoi.c libft42/ft_isascii.c libft42/ft_memcmp.c libft42/ft_putendl_fd.c libft42/ft_striteri.c libft42/ft_strmapi.c libft42/ft_toupper.c libft42/ft_bzero.c  libft42/ft_isdigit.c libft42/ft_memcpy.c libft42/ft_putnbr_fd.c libft42/ft_strjoin.c libft42/ft_strncmp.c libft42/ft_calloc.c libft42/ft_isprint.c libft42/ft_memmove.c libft42/ft_putstr_fd.c libft42/ft_strlcat.c libft42/ft_strrchr.c libft42/ft_isalnum.c libft42/ft_itoa.c libft42/ft_memset.c libft42/ft_strchr.c libft42/ft_strlcpy.c libft42/ft_substr.c libft42/ft_split.c libft42/ft_strtrim.c libft42/ft_strnstr.c libft42/ft_lstnew.c libft42/ft_lstadd_front.c libft42/ft_lstsize.c libft42/ft_lstlast.c libft42/ft_lstadd_back.c libft42/ft_lstdelone.c libft42/ft_lstclear.c libft42/ft_lstiter.c libft42/ft_lstmap.c

SRC_PERSO = perso/ft_is_lower.c perso/ft_is_upper.c perso/ft_itoa_base.c perso/ft_nbrlen.c perso/ft_putchar.c perso/ft_putstr.c perso/ft_str_to_lowercase.c perso/ft_str_to_uppercase.c perso/ft_strcat.c perso/ft_strcombine.c perso/ft_strcpy.c perso/ft_strlen_to_char.c perso/ft_strndup.c perso/ft_strrev.c perso/ft_power.c perso/ft_putendl.c perso/ft_putnbr.c perso/ft_strcombine_char.c perso/ft_str_is_num.c perso/ft_stradd.c perso/ft_atoi_big.c perso/ft_tablen.c perso/ft_str_is.c perso/ft_free_tab.c perso/ft_display_tab.c perso/ft_int_too_big.c perso/ft_display_bits_int.c perso/ft_check_ext.c perso/ft_read_file.c

OBJ_GET_NEXT_LINE = $(SRC_GET_NEXT_LINE:.c=.o)

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

OBJ_LIBFT42 = $(SRC_LIBFT42:.c=.o)

OBJ_PERSO = $(SRC_PERSO:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_LIBFT42) $(OBJ_PERSO) $(OBJ_PRINTF) $(OBJ_GET_NEXT_LINE)
	ar -qcs $(NAME) $(OBJ_LIBFT42) $(OBJ_PERSO) $(OBJ_PRINTF) $(OBJ_GET_NEXT_LINE)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f */*.o
	rm -f */*/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
