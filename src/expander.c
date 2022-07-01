/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:46:59 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 16:11:12 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_make_pipe(void)
{
	int	*tube;

	tube = ft_calloc(2, sizeof(int));
	if (tube == NULL)
		return (NULL);
	pipe(tube);
	return (tube);
}

int	**ft_make_pipe_list(int nb)
{
	int	**pipe_list;
	int	i;

	pipe_list = ft_calloc(nb, sizeof(int *));
	if (pipe_list == NULL)
		return (NULL);
	i = 0;
	while (i < nb - 1)
	{
		pipe_list[i] = ft_make_pipe();
		i++;
	}
	pipe_list[i] = NULL;
	return (pipe_list);
}

void	ft_init_cmd_in_out(t_cmd_table *cmd_table)
{
	int		i;
	int		**pipe_list;
	t_cmd	*cmd_array;

	pipe_list = ft_make_pipe_list(cmd_table->cmd_count);
	cmd_array = cmd_table->cmd_array;
	i = 0;
	cmd_array[i].fd_in = 0;
	while (i < cmd_table->cmd_count - 1)
	{
		cmd_array[i].fd_out = pipe_list[i][1];
		i++;
		cmd_array[i].fd_in = pipe_list[i - 1][0];
	}
	cmd_array[i].fd_out = 1;
	ft_free_tab_int(pipe_list);
}

//À pour but de créer les pipes et l'entrée et sortie pour les assigner à
//chaque process.
void	ft_expander(t_cmd_table *cmd_table)
{
	if (cmd_table == NULL)
		return ;
	ft_init_cmd_in_out(cmd_table);
}
