/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:09:25 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/02/19 16:10:23 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

void	ft_free_big_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_free_tab(tab[i++]);
	free(tab);
}