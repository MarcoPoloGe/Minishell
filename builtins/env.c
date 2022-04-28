/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:43:12 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/28 14:43:12 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	ft_display_env(char **env)
{
	while (*env)
	{
		ft_putstr(*env);
		ft_putchar('\n');
		env++;
	}
}
/*
int	main(int argc, char **argv, char **env)
{
	ft_display_env(env);
	return(0);
}*/