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
#include "../minishell.h"

void ft_exit(int argc, char **argv, t_cmd_table *table)
{
	int x;

	x = 0; //todo intergrate argv use of exit;
	if (ft_isalldigit(arg))
		x = ft_atoi(arg);
	ft_free_struct(&table);
	exit(x);
}
