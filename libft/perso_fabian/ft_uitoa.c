/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:02:50 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/12 15:03:36 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "perso_fabian.h"

static int	ft_nb_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_convert_ui_to_c(char *str, unsigned int n, int len)
{
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

int	ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_nb_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (ft_putchar_len('\0'));
	str[len--] = '\0';
	if (n == 0)
	{
		free(str);
		return (ft_putchar_len('0'));
	}
	str = ft_convert_ui_to_c(str, n, len);
	len = ft_putstr_len(str);
	free(str);
	return (len);
}
