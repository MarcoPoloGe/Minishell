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

	x = 0;
	while (tab[x])
	{
		if (x != 0)
			ft_putstr(", ");
		ft_printf("<%s>", tab[x]);
		x++;
	}
}

void	ft_display_two_way_table(char ***tab)
{
	int	y;

	if (!tab)
		return ;
	y = 0;
	ft_putstr("--- Start ---");
	y++;
	while (tab[y])
	{
		ft_display_table(tab[y]);
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
}

void	ft_display_cmd_table(t_cmd_table *cmd_table)
{
	int	i;

	if (cmd_table == NULL)
		return ;
	i = 0;
	ft_putstr("--- cmd_table_start ---\n");
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

t_cmd_table	ft_create_cmd_table(void)
{
	t_cmd_table	cmd_table;
	t_cmd		*cmd_array;

	cmd_table.cmd_array = ft_calloc(3, sizeof(t_cmd_table));
	cmd_array = cmd_table.cmd_array;
	cmd_array[0].cmd = ft_strdup("cmd1");
	cmd_array[0].args = ft_split("arg1 arg2", ' ');
	cmd_array[1].cmd = ft_strdup("cmd2");
	cmd_array[1].args = ft_split("arg1 arg2", ' ');
	cmd_array[2].cmd = NULL;
	cmd_array[2].args = NULL;
	ft_display_cmd_table(&cmd_table);
	return (cmd_table);
}

t_cmd_table	ft_create_cmd_table_realistic(void)
{
	t_cmd_table	cmd_table;
	t_cmd		*cmd_array;

	cmd_table.cmd_array = ft_calloc(3, sizeof(t_cmd_table));
	cmd_array = cmd_table.cmd_array;
	cmd_array[0].cmd = ft_strdup("ls");
	cmd_array[0].args = ft_split("libft rendu", ' ');
	cmd_array[1].cmd = ft_strdup("grep");
	cmd_array[1].args = ft_split("ft_putchar.c", ' ');
	cmd_array[2].cmd = NULL;
	cmd_array[2].args = NULL;
	ft_display_cmd_table(&cmd_table);
	return (cmd_table);
}
