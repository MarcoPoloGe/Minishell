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

char ***ft_delete_str_tab(char ***tab, char *str)
{
	int i;
	int y;
	char ***ret;

	i = 0;
	y = 0;
	ret = ft_calloc(sizeof(char **), ft_tablen(*tab) - 1);
	while (tab[i])
	{
		if (!ft_str_same(str, tab[i][0]))
			ret[y++] = tab[i];
		i++;
	}
	return (ret);
}
