/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:54:15 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 16:08:39 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_display_table(char **tab)
{
	int	x;

	if (tab == NULL || *tab == NULL)
		return ;
	ft_putstr("[ ");
	x = 0;
	while (tab[x])
	{
		if (x != 0)
			ft_putstr(", ");
		ft_printf("#%s#", tab[x]);
		x++;
	}
	ft_putstr(" ]\n");
}

void	ft_display_two_way_table(char ***tab)
{
	int	y;

	if (!tab)
		return ;
	y = 0;
	ft_putstr("--- Start ---\n");
	while (tab[y])
	{
		ft_display_table(tab[y]);
		ft_putchar('\n');
		y++;
	}
	ft_putstr("--- End ---");
}

void	ft_display_cmd(t_cmd cmd)
{
	ft_putstr("[");
	ft_putstr("CMD: ");
	ft_printf("<%s>", cmd.cmd);
	ft_putstr("][");
	ft_putstr("ARGS: ");
	ft_display_table(cmd.args);
	ft_putstr("]");
	ft_putstr("\n");
	ft_putstr("[");
	ft_putstr("fd_in: ");
	ft_printf("<%i>", cmd.fd_in);
	ft_putstr("][");
	ft_putstr("fd_out: ");
	ft_printf("<%i>", cmd.fd_out);
	ft_putstr("]");
	ft_putstr("\n");
}

void	ft_display_cmd_table(t_cmd_table *cmd_table)
{
	int	i;

	if (cmd_table == NULL)
		return ;
	i = 0;
	ft_putstr("--- cmd_table_start ---\n");
	ft_printf("cmd_count      :%i\n", cmd_table->cmd_count);
	ft_printf("io_out         :%i\n", cmd_table->io_out);
	ft_printf("io_in          :%i\n", cmd_table->io_in);
	ft_printf("io_extract_fd  :%i\n", cmd_table->io_extract_fd);
	ft_printf("io_insert_flag :%i\n", cmd_table->io_insert_flag);
	while (cmd_table->cmd_array[i].cmd != NULL)
	{
		ft_display_cmd(cmd_table->cmd_array[i]);
		i++;
	}
	ft_putstr("--- cmd_table_end ---\n");
}

void	ft_display_lexer_tokens(char **tokens_tab)
{
	int	i;

	if (tokens_tab == NULL)
		return ;
	i = 0;
	ft_putstr("--- token_table_start ---\n");
	while (tokens_tab[i] != NULL)
	{
		ft_printf("<%s>", tokens_tab[i]);
		i++;
	}
	ft_putstr("--- token_table_end ---\n");
}
