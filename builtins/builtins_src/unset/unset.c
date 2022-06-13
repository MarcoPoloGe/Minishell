/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:40:45 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/13 14:40:45 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../src/minishell.h"

void	ft_delete_env_str(t_cmd_table *table, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		table->env = ft_delete_str_tab(table->env, args[i++]);
}

void	ft_unset(t_cmd_table *table, char **args)
{
	if (args != NULL)
		ft_delete_env_str(table, args);
}