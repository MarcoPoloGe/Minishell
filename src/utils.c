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

#include "minishell.h"

t_cmd_table	*ft_free_struct(t_cmd_table *table)
{
	int i;

	i = 0;
	while (table->cmd_array[i].cmd)
	{
		free(table->cmd_array[i].cmd);
		if (table->cmd_array[i].args)
			ft_free_tab(table->cmd_array[i].args);
		i++;
	}
	free(table->cmd_array);
	if (table->io_in)
		free(table->io_in);
	if (table->io_out)
		free(table->io_out);
	ft_free_tab(table->env);
	free(table);
	table = NULL;
	return (table);
}