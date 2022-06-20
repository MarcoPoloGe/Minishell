NAME = libft.a

SRC_GET_NEXT_LINE = get_next_line.c

SRC_PRINTF = ft_printf.c printf_utils/ft_itoa_base_16.c printf_utils/ft_print_pointer_len.c printf_utils/ft_putchar_len.c printf_utils/ft_putnbr_len.c printf_utils/ft_putstr_len.c printf_utils/ft_puthexa_len.c

SRC_LIBFT42 = ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strdup.c ft_strlen.c ft_tolower.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_striteri.c ft_strmapi.c ft_toupper.c ft_bzero.c  ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strncmp.c ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalnum.c ft_itoa.c ft_memset.c ft_strchr.c ft_strlcpy.c ft_substr.c ft_split.c ft_strtrim.c ft_strnstr.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_PERSO_FABIAN = ft_atoi_long.c ft_isalldigit.c ft_itohex.c ft_uitoa.c ft_sort_str_tab.c ft_delete_str_tab.c

SRC_PERSO_MARCO = ft_is_lower.c ft_is_upper.c ft_itoa_base.c ft_nbrlen.c ft_putchar.c ft_putstr.c ft_str_to_lowercase.c ft_str_to_uppercase.c ft_strcat.c ft_strcombine.c ft_strcpy.c ft_strlen_char.c ft_strndup.c ft_strrev.c ft_power.c ft_putendl.c ft_putnbr.c ft_strcombine_char.c ft_str_is_num.c ft_stradd.c ft_atoi_big.c ft_tablen.c ft_str_same.c ft_free_tab.c ft_display_tab.c ft_int_too_big.c ft_display_bits_int.c ft_check_ext.c ft_read_file.c ft_str_match.c ft_tabcpy.c ft_tabadd.c ft_isspace.c ft_stradd_len.c ft_tabadd_len.c ft_skip_spaces.c ft_read_two_way_tab.c ft_tabdup.c ft_tabadd_front.c ft_tabcat.c ft_tab_combine.c ft_tablcpy.c ft_tabndup.c ft_tabdel.c ft_tablast.c ft_free_big_tab.c ft_big_tablen.c ft_display_big_tab.c ft_read_fd.c

SRC_PATH := $(foreach wrd,$(SRC_GET_NEXT_LINE),get_next_line/$(wrd)) $(foreach wrd,$(SRC_PRINTF),printf/$(wrd)) $(foreach wrd,$(SRC_LIBFT42),libft42/$(wrd)) $(foreach wrd,$(SRC_PERSO_FABIAN),perso_fabian/$(wrd)) $(foreach wrd,$(SRC_PERSO_MARCO),perso_marco/$(wrd))

OBJ_PATH = $(SRC_PATH:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_PATH)
	ar -qcs $(NAME) $(OBJ_PATH)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f */*.o
	rm -f */*/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
