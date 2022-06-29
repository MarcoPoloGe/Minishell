/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_dup_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:06:15 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/29 15:06:16 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_dup_cmd_pipes(t_cmd *cmd)
{
	if (cmd->fd_in > 0)
		dup2(cmd->fd_in, 0);
	if (cmd->fd_out > 1)
		dup2(cmd->fd_out, 1);
}

void	ft_close_cmd_pipes(t_cmd *cmd)
{
	if (cmd->fd_in > 0)
		close(cmd->fd_in);
	if (cmd->fd_out > 1)
		close(cmd->fd_out);
}

void	ft_close_unrelated_pipes(t_cmd *cmd, t_cmd_table *cmd_table)
{
	int	i;

	i = 0;
	while (i < cmd_table->cmd_count)
	{
		if (cmd_table->cmd_array + i != cmd)
			ft_close_cmd_pipes(cmd_table->cmd_array + i);
		i++;
	}
}
