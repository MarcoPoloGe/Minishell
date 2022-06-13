/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:31:57 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/09 11:31:57 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../src/minishell.h"

void	ft_exit(t_cmd_table *table, char *arg)
{
	int x;

	x = 0;
	if (ft_isalldigit(arg))
		x = ft_atoi(arg);
	ft_free_struct(&table);
	exit(x);
}

void	ft_is_exit(t_cmd_table *table, char *str, char *arg)
{
	if (ft_str_same(str, "exit"))
		ft_exit(table, arg);
}