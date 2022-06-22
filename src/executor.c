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

void	ft_launch_special_builtins(t_cmd *cmd, t_cmd_table *cmd_table)
{
	int	term_in;
	int	term_out;

	term_out = dup(1);
	term_in = dup(0);
	dup2(cmd->fd_in, 0);
	dup2(cmd->fd_out, 1);
	//if(ft_str_same(cmd->cmd, BUILTIN_CD))
		// todo cd ;
	if (ft_str_same(cmd->cmd, BUILTIN_EXIT))
		ft_exit(ft_tablen(cmd->args), cmd->args, cmd_table);
	else if (ft_str_same(cmd->cmd, BUILTIN_EXPORT))
		ft_export(ft_tablen(cmd->args), cmd->args);
	else if (ft_str_same(cmd->cmd, BUILTIN_UNSET))
		ft_unset(ft_tablen(cmd->args), cmd->args);
	dup2(term_out, 1);
	dup2(term_in, 0);
}

void	ft_child(t_cmd *cmd)
{
	dup2(cmd->fd_in, 0);
	dup2(cmd->fd_out, 1);
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
		signals_fork();
		if (ft_is_builtin(cmd_table->cmd_array[i].cmd))
			ft_launch_special_builtins((cmd_table->cmd_array + i), cmd_table);
		else
		{
			if (fork() == 0)
				ft_child((cmd_table->cmd_array + i));
			else
			{
				wait(NULL);
				if (cmd_table->cmd_array[i].fd_out != 1)
					close(cmd_table->cmd_array[i].fd_out);
				if (cmd_table->cmd_array[i].fd_in != 0)
					close(cmd_table->cmd_array[i].fd_in);
			}
		}
		i++;
	}
}
