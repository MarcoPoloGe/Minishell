/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:10:50 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/24 17:46:18 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_utils.h"

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}
