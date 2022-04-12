/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:25:54 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/24 17:44:26 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_utils.h"

int	ft_putstr_len(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
