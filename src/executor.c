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

void	ft_child(t_cmd *cmd, char **env)
{
	dup2(cmd->fd_in, 0);
	dup2(cmd->fd_out, 1);
	execve(cmd->cmd, cmd->args, env);
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
			ft_child((cmd_table->cmd_array + i), cmd_table->env);
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

t_cmd_table	ft_create_cmd_table_executable(void)
{
	t_cmd_table	cmd_table;
	t_cmd		*cmd_array;

	cmd_table.cmd_array = ft_calloc(3, sizeof(t_cmd_table));
	cmd_table.cmd_count = 2;
	cmd_array = cmd_table.cmd_array;
	cmd_array[0].cmd = ft_strdup("philosophers");
	cmd_array[0].args = ft_split("libft rendu", ' ');
	cmd_array[1].cmd = ft_strdup("philosophers");
	cmd_array[1].args = ft_split("ft_putchar.c", ' ');
	cmd_array[2].cmd = NULL;
	cmd_array[2].args = NULL;
	ft_display_cmd_table(&cmd_table);
	return (cmd_table);
}
