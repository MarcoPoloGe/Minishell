/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:17:14 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/12 15:10:11 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSO_FABIAN_H
# define PERSO_FABIAN_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft42/libft42.h"
# include "../printf/ft_printf.h"
# include "../perso_marco/perso_marco.h"

long	ft_atoi_long(const char *str);
int		ft_uitoa(unsigned int n);
int		ft_itohex(unsigned int num, char c);
int		ft_isalldigit(char *str);
char	**ft_sort_str_tab(char **tab);
char 	***ft_delete_str_tab(char ***tab, char *str);
int		ft_count_char(char c, char *str);
#endif
