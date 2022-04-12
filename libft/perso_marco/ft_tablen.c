/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:18:25 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/02/13 16:18:31 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

int	ft_tablen(void **tab)
{
	int	count;

	count = 0;
	while (tab && (*tab) && tab[count] != NULL)
		count++;
	return (count);
}
