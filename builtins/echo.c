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

void	ft_display_env(char **env, int i, int y)
{
	while (env[y][i])
	{
		ft_putchar(env[y][i]);
		i++;
	}
}

int	ft_check_env(char *str, char **env)
{
	int	i;
	int	y;
	int	len;

	y = 0;
	while (env[y])
	{
		i = 0;
		while (env[y][i] == ft_toupper(str[i]))
			i++;
		len = i;
		if (env[y][i] == '=' && (ft_isalnum(str[i]) == 0 && str[i] != '_'))
		{
			ft_display_env(env, i + 1, y);
			return (len + 1);
		}
		y++;
	}
	i = 0;
	while ((ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	return (i + 1);
}

void	ft_echo(char *str, int nl, char **env)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			i += ft_check_env(str + i + 1, env);
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
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