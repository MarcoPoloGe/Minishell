/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:53:56 by facolomb          #+#    #+#             */
/*   Updated: 2021/11/11 10:53:56 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "perso_fabian.h"

static int	ft_len_hex(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_print_hex(unsigned int num, char c)
{
	if (num >= 16)
	{
		ft_print_hex(num / 16, c);
		ft_print_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (c == 'x')
				ft_putchar(num + 87);
			if (c == 'X')
				ft_putchar(num + 55);
		}
	}
}

int	ft_itohex(unsigned int num, char c)
{
	ft_print_hex(num, c);
	return (ft_len_hex(num));
}
