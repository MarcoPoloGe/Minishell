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
#include "../../../src/minishell.h"

int	ft_is_nl(char *str)
{
	if (str[0] == '-')
	{
		if (ft_str_same(str, "-n"))
			return (1);
		else
			ft_error("Error : echo unkown option", NULL, NULL);
	}
	else
	{
		ft_putstr(str);
		return (0);
	}
}

void	ft_echo(char **args)
{
	int	i;
	int	tablen;
	int	nl;

	i = 0;
	tablen = ft_tablen(args);
	while (i < tablen)
	{
		if (i == tablen - 1)
			nl = ft_is_nl(args[i]);
		else
			ft_putstr(args[i]);
		i++;
	}
	if (nl == 1)
		ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		ft_echo(argv);
	return (0);
}
