/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:30:51 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/13 13:30:51 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "perso_fabian.h"

char	**ft_sort_str_tab(char **tab)
{
	int		i;
	int		tablen;
	int		ordered;
	char	*tmp;

	ordered = 0;
	tablen = ft_tablen(tab);
	while (ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < tablen - 1)
		{
			if (ft_strncmp(tab[i], tab[i + 1], ft_strlen(tab[i])) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				ordered = 0;
			}
			i++;
		}
		tablen--;
	}
	return (tab);
}
