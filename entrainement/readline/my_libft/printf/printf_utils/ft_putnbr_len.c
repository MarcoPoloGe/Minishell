/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:10:36 by mbelarbi          #+#    #+#             */
/*   Updated: 2021/10/24 17:54:32 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf_utils.h"

int	ft_putnbr_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar_len('-');
		n = -n;
	}
	if (n / 10 != 0)
	{
		len += ft_putnbr_len(n / 10);
	}
	len += ft_putchar_len(n % 10 + '0');
	return (len);
}
