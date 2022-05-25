/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:54:20 by facolomb          #+#    #+#             */
/*   Updated: 2022/05/24 16:38:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	ft_init_env(t_cmd_table *table, char **env)
{
	while(*env)
	{
		ft_tabadd(&table->env, *env);
		env++;
	}
}

void ft_init_table(t_cmd_table *table, int nb_cmd, char **env)
{
	t_cmd		*cmd;
	int			i;

	table = ft_calloc(1, sizeof(t_cmd_table));
	i = 0;
	table->cmd_array = ft_calloc(nb_cmd + 1, sizeof(t_cmd));
	cmd = table->cmd_array;
	while (i <= nb_cmd)
	{
		cmd[i].cmd = NULL;
		cmd[i].fd_in = 0;
		cmd[i].fd_out = 0;
		i++;
	}
	table->cmd_count = nb_cmd;
	table->io_in = NULL;
	table->io_out = NULL;
	table->io_extract_fd = -1;
	table->io_insert_flag = -1;
	ft_init_env(table, env);
}