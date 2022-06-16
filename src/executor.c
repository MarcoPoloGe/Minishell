/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:38:53 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/24 16:15:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_child(t_cmd *cmd)
{
	dup2(cmd->fd_in, 0);
	dup2(cmd->fd_out, 1);
	//if(cmd ft_is_special_builtin)
	//	cmd->fd_ou;
	execve(cmd->cmd, cmd->args, ft_read_env_simple());
}

void	ft_executor(t_cmd_table *cmd_table)
{
	int	i;

	if (cmd_table == NULL)
		return ;
	i = 0;
	while (i < cmd_table->cmd_count)
	{
		if (fork() == 0)
		{
			ft_child((cmd_table->cmd_array + i));
		}
		else
		{
			wait(NULL);
			if(cmd_table->cmd_array[i].fd_out != 1)
				close(cmd_table->cmd_array[i].fd_out);
			if(cmd_table->cmd_array[i].fd_in != 0)
				close(cmd_table->cmd_array[i].fd_in);
		}
		i++;
	}
}
