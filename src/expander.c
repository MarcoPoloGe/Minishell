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

int	ft_open_io(char *io, int flags)
{
	int	fd;

	if (io != NULL)
	{
		fd = open(io, flags);
		if (fd < 0)
			ft_printf("Error : file opening or creation."); //todo better
	}
	else
		return (0);
	return (fd);
}

int	ft_init_input(t_cmd_table *cmd_table)
{
	if (cmd_table->io_in == NULL)
		return (0);
	if (cmd_table->io_extract_fd)
	{
		//todo not sure if extraction should happen here or in the parser.
		return (0);
	}
	else
		return (ft_open_io(cmd_table->io_in, O_RDONLY));
}

int	ft_init_output(t_cmd_table *cmd_table)
{
	if (cmd_table->io_out == NULL)
		return (1);
	if (cmd_table->io_insert_flag)
		return (ft_open_io(cmd_table->io_out, O_WRONLY | O_APPEND));
	else
		return (ft_open_io(cmd_table->io_out, O_WRONLY));
}

void	ft_init_cmd_in_out(t_cmd_table *cmd_table)
{
	int		i;
	int		**pipe_list;
	t_cmd	*cmd_array;

	pipe_list = ft_make_pipe_list(cmd_table->cmd_count);
	cmd_array = cmd_table->cmd_array;
	i = 0;
	cmd_array[i].fd_in = ft_init_input(cmd_table);
	while (i < cmd_table->cmd_count - 1)
	{
		cmd_array[i].fd_out = pipe_list[i][1];
		i++;
		cmd_array[i].fd_in = pipe_list[i - 1][0];
	}
	cmd_array[i].fd_out = ft_init_output(cmd_table);
}

//À pour but de créer les pipes et l'entrée et sortie pour les assigner à
//chaque process.
void	ft_expander(t_cmd_table *cmd_table)
{
	ft_init_cmd_in_out(cmd_table);
}
