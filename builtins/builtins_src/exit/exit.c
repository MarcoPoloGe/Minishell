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

void	ft_exit(t_cmd_table *table)
{
	ft_free_struct(&table);
	exit(0);
}

void	ft_is_exit(t_cmd_table *table, char *str)
{
	if (ft_str_same(str, "exit"))
		ft_exit(table);
}