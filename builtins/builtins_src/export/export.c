/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:08:36 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/09 15:08:36 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../src/minishell.h"

void	ft_add_export(t_cmd_table *table, char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (ft_isalpha(args[i][0]))
			ft_tabadd(&table->env, args[i]);
		else
			ft_error("export, not a valid identifier ", &table, NULL);
		i++;
	}
}

void	ft_display_export(char **tab)
{
	int i;

	i = 0;
	tab = ft_sort_str_tab(tab);
	while (tab[i])
		ft_printf("declare -x %s\n", tab[i++]);
}

void	ft_export(t_cmd_table *table, char **args)
{
	if (!args)
		ft_display_export(table->env);
	else
		ft_add_export(table, args);
}