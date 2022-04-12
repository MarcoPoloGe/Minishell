/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:28:05 by facolomb          #+#    #+#             */
/*   Updated: 2021/10/27 09:37:33 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "perso_fabian.h"

static char	*ft_trim(const char *str)
{
	char	*ret;

	while (*str == ' ' || *str == '\t'
		|| *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\n')
	{
		str++;
	}
	ret = (char *)str;
	return (ret);
}

static int	ft_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
	}
	return (sign);
}

long	ft_atoi_long(const char *str)
{
	long	res;
	int		i;
	int		sign;
	char	*trimed;

	res = 0;
	i = 0;
	trimed = ft_trim(str);
	sign = ft_sign(trimed);
	if (trimed[i] == '-' || trimed[i] == '+')
		i++;
	while (trimed[i] >= '0' && trimed[i] <= '9')
	{
		res = res * 10 + trimed[i] - '0';
		i++;
	}
	return (res * sign);
}
