/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:27:18 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/07 12:27:20 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso.h"

int	ft_strlen_to_char(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}
