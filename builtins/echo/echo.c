/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:28:49 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/26 11:28:49 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft/libft.h"

int	ft_is_nl(char *str)
{
	if (ft_str_same(str, "-n"))
		return (1);
	else
		return (0);
}

void	ft_echo(int argc, char **args)
{
	int	i;
	int	nl;

	i = 1;
	nl = ft_is_nl(args[i]);
	if (nl)
		i++;
	while (i < argc)
	{
		ft_putstr(args[i]);
		if (i < argc - 1)
			ft_putchar(' ');
		i++;
	}
	if (nl == 0)
		ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		ft_echo(argc, argv);
	else
		ft_putchar('\n');
	return (0);
}
