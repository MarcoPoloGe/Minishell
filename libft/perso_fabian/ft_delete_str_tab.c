/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_str_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:56:40 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/13 14:56:40 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "perso_fabian.h"

char	**ft_delete_str_tab(char **tab, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (tab[i])
	{
		if ((ft_str_match(tab[i], str)
				&& (tab[i][len] == '=' || tab[i][len] == '\0')))
			break ;
		i++;
	}
	ft_tabdel(tab, i);
	return (tab);
}
