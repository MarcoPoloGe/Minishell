/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:23:54 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 15:28:31 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_free_struct(t_cmd_table **table_adress)
{
	t_cmd_table *table;
	int i;

	if (table_adress == NULL || *table_adress == NULL)
		return ;
	table = *table_adress;
	i = 0;
	while (table->cmd_array[i].cmd)
	{
		free(table->cmd_array[i].cmd);
		if (table->cmd_array[i].args)
			ft_free_tab(table->cmd_array[i].args);
		i++;
	}
	free(table->cmd_array);
	ft_free_tab(table->env);
	free(table);
	table = NULL;
}

void ft_error(char *message, t_cmd_table **table) //todo better
{
	ft_printf("Error : %s\n", message);
	ft_free_struct(table);
}

void ft_fatal_error(char *message, t_cmd_table **table) //todo better
{
	ft_printf("Fatal Error : %s\n", message);
	ft_free_struct(table);
	exit(1);
}