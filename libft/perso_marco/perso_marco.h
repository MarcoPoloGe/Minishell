/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:20:21 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/04/18 14:33:59 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSO_MARCO_H
# define PERSO_MARCO_H
# include "../libft42/libft42.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

int		ft_is_lower(int c);
int		ft_is_upper(int c);
char	*ft_itoa_base(int nb, int base);
int		ft_nbrlen(int nbr, int base);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_str_to_lowercase(char *str);
char	*ft_str_to_uppercase(char *str);
size_t	ft_strcat(char *dst, char *str);
char	*ft_strcombine(char *s1, char *s2);
size_t	ft_strcpy(char *dst, char *str);
int		ft_strlen_to_char(char *str, char c);
char	*ft_strndup(char *str, int n);
char	*ft_strrev(char *str);
int		ft_power(int nb, int power);
void	ft_putnbr(int n);
void	ft_putendl(char *str);
char	*ft_strcombine_char(char *s1, char c);
int		ft_str_is_num(char *str);
void	ft_stradd(char **s1, char *s2);
long	ft_atoi_big(char *str);
int		ft_tablen(void **tab);
int		ft_str_same(char *s1, char *s2);
void	ft_free_tab(char **tab);
void	ft_display_tab(char **tab);
int		ft_int_too_big(char *str);
void	ft_display_bits_int(int nb);
int		ft_check_ext(char *file, char *ext);
char	*ft_read_file(char *file_name, char *ext);
int		ft_str_match(char *hay, char *needle);

#endif
