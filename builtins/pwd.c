/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:33:08 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/28 14:33:08 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../src/minishell.h"

void	ft_display_pwd(char **env)
{
	int	i;
	int	y;

	i = 4;
	y = 0;
	while (env[y])
	{
		if (ft_strncmp(env[y], "PWD", 3) == 0)
		{
			while (env[y][i])
			{
				ft_putchar(env[y][i]);
				i++;
			}
		}
		y++;
	}
}
/*
int	main(int argc, char **argv, char **env)
{
	ft_display_pwd(env);
	return(0);
}*/