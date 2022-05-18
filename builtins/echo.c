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
#include "../src/minishell.h"

void	ft_echo(char *str, int nl)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	if (nl == 1)
		ft_putchar('\n');
}
/*
int	main(int argc, char **argv, char **env)
{
	ft_echo("test$path", 1, env);
	return (0);
}
*/