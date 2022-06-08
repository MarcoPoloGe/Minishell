NAME = libft.a

SRC_GET_NEXT_LINE = get_next_line/get_next_line.c

SRC_PRINTF = printf/ft_printf.c printf/printf_utils/ft_itoa_base_16.c printf/printf_utils/ft_print_pointer_len.c printf/printf_utils/ft_putchar_len.c printf/printf_utils/ft_putnbr_len.c printf/printf_utils/ft_putstr_len.c printf/printf_utils/ft_puthexa_len.c

SRC_LIBFT42 = libft42/ft_isalpha.c libft42/ft_memchr.c libft42/ft_putchar_fd.c libft42/ft_strdup.c libft42/ft_strlen.c libft42/ft_tolower.c libft42/ft_atoi.c libft42/ft_isascii.c libft42/ft_memcmp.c libft42/ft_putendl_fd.c libft42/ft_striteri.c libft42/ft_strmapi.c libft42/ft_toupper.c libft42/ft_bzero.c  libft42/ft_isdigit.c libft42/ft_memcpy.c libft42/ft_putnbr_fd.c libft42/ft_strjoin.c libft42/ft_strncmp.c libft42/ft_calloc.c libft42/ft_isprint.c libft42/ft_memmove.c libft42/ft_putstr_fd.c libft42/ft_strlcat.c libft42/ft_strrchr.c libft42/ft_isalnum.c libft42/ft_itoa.c libft42/ft_memset.c libft42/ft_strchr.c libft42/ft_strlcpy.c libft42/ft_substr.c libft42/ft_split.c libft42/ft_strtrim.c libft42/ft_strnstr.c libft42/ft_lstnew.c libft42/ft_lstadd_front.c libft42/ft_lstsize.c libft42/ft_lstlast.c libft42/ft_lstadd_back.c libft42/ft_lstdelone.c libft42/ft_lstclear.c libft42/ft_lstiter.c libft42/ft_lstmap.c

SRC_PERSO_FABIAN = perso_fabian/ft_atoi_long.c perso_fabian/ft_isalldigit.c perso_fabian/ft_itohex.c perso_fabian/ft_uitoa.c

SRC_PERSO_MARCO = perso_marco/ft_is_lower.c perso_marco/ft_is_upper.c perso_marco/ft_itoa_base.c perso_marco/ft_nbrlen.c perso_marco/ft_putchar.c perso_marco/ft_putstr.c perso_marco/ft_str_to_lowercase.c perso_marco/ft_str_to_uppercase.c perso_marco/ft_strcat.c perso_marco/ft_strcombine.c perso_marco/ft_strcpy.c perso_marco/ft_strlen_to_char.c perso_marco/ft_strndup.c perso_marco/ft_strrev.c perso_marco/ft_power.c perso_marco/ft_putendl.c perso_marco/ft_putnbr.c perso_marco/ft_strcombine_char.c perso_marco/ft_str_is_num.c perso_marco/ft_stradd.c perso_marco/ft_atoi_big.c perso_marco/ft_tablen.c perso_marco/ft_str_same.c perso_marco/ft_free_tab.c perso_marco/ft_display_tab.c perso_marco/ft_int_too_big.c perso_marco/ft_display_bits_int.c perso_marco/ft_check_ext.c perso_marco/ft_read_file.c perso_marco/ft_str_match.c perso_marco/ft_tabcpy.c perso_marco/ft_tabadd.c perso_marco/ft_isspace.c perso_marco/ft_stradd_len.c perso_marco/ft_tabadd_len.c perso_marco/ft_skip_spaces.c perso_marco/ft_read_two_way_tab_file.c perso_marco/ft_tabdup.c perso_marco/ft_tabadd_front.c perso_marco/ft_tabcat.c perso_marco/ft_tab_combine.c perso_marco/ft_tablcpy.c perso_marco/ft_tabndup.c perso_marco/ft_tabdel.c

OBJ_GET_NEXT_LINE = $(SRC_GET_NEXT_LINE:.c=.o)

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

OBJ_LIBFT42 = $(SRC_LIBFT42:.c=.o)

OBJ_PERSO_FABIAN = $(SRC_PERSO_FABIAN:.c=.o)

OBJ_PERSO_MARCO = $(SRC_PERSO_MARCO:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_LIBFT42) $(OBJ_PERSO_MARCO) $(OBJ_PERSO_FABIAN) $(OBJ_PRINTF) $(OBJ_GET_NEXT_LINE)
	ar -qcs $(NAME) $(OBJ_LIBFT42) $(OBJ_PERSO_MARCO) $(OBJ_PERSO_FABIAN) $(OBJ_PRINTF) $(OBJ_GET_NEXT_LINE)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f */*.o
	rm -f */*/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
