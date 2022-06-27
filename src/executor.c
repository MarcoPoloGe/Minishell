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

void ft_dup_cmd_pipes(t_cmd *cmd)
{
	if(cmd->fd_in > 0)
		dup2(cmd->fd_in, 0);
	if(cmd->fd_out > 1)
		dup2(cmd->fd_out, 1);
}

void ft_close_cmd_pipes(t_cmd *cmd)
{
	if(cmd->fd_in > 0)
		close(cmd->fd_in);
	if(cmd->fd_out > 1)
		close(cmd->fd_out);
}

void	ft_launch_special_builtins(t_cmd *cmd, t_cmd_table *cmd_table)
{
	int	term_in;
	int	term_out;

	term_out = dup(1);
	term_in = dup(0);
	ft_dup_cmd_pipes(cmd);
	if(ft_str_same(cmd->cmd, BUILTIN_CD))
		ft_cd(ft_tablen(cmd->args), cmd->args, cmd_table);
	else if (ft_str_same(cmd->cmd, BUILTIN_EXIT))
		ft_exit(ft_tablen(cmd->args), cmd->args, cmd_table);
	else if (ft_str_same(cmd->cmd, BUILTIN_EXPORT))
		ft_export(ft_tablen(cmd->args), cmd->args);
	else if (ft_str_same(cmd->cmd, BUILTIN_UNSET))
		ft_unset(ft_tablen(cmd->args), cmd->args);
	dup2(term_out, 1);
	dup2(term_in, 0);
}

void	ft_close_unrelated_pipes(t_cmd *cmd, t_cmd_table *cmd_table)
{
	int i;

	i = 0;
	while (i < cmd_table->cmd_count)
	{
		if(cmd_table->cmd_array + i != cmd)
			ft_close_cmd_pipes(cmd_table->cmd_array + i);
		i++;
	}
}

void	ft_child(t_cmd *cmd, t_cmd_table *cmd_table)
{
	ft_close_unrelated_pipes(cmd, cmd_table);
	ft_dup_cmd_pipes(cmd);
	execve(cmd->cmd, cmd->args, ft_env(NULL));
}

//a pour but de lancer les forks doit retourner le pid du fork correspondant a la cmd donnée
int ft_launch_cmd(t_cmd *cmd, t_cmd_table *cmd_table)
{
	int pid;

	if (ft_is_builtin(cmd->cmd))
		ft_launch_special_builtins(cmd, cmd_table);
	else
	{
		pid = fork();
		if (pid == 0)
			ft_child(cmd, cmd_table);
		else
			return (pid);
	}
	return (-1);
}

void ft_wait_pid_list(int *pid_list, t_cmd_table *cmd_table)
{
	int status;
	int i;

	i = 0;

	while (i < cmd_table->cmd_count)
	{
		if(pid_list[i] > 0)
		{
			waitpid(pid_list[i], &status, 0);
		}
		ft_close_cmd_pipes(cmd_table->cmd_array + i);
		i++;
	}
}

void	ft_executor(t_cmd_table *cmd_table)
{
	int *pid_list;
	int	i;

	signals_fork();
	if (cmd_table == NULL)
		return ;
	pid_list = calloc(cmd_table->cmd_count, sizeof(int));
	i = 0;
	while (i < cmd_table->cmd_count)
	{
		pid_list[i] = ft_launch_cmd(cmd_table->cmd_array + i, cmd_table);
		i++;
	}
	ft_wait_pid_list(pid_list, cmd_table);
}
