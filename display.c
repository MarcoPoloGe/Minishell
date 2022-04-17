/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:54:15 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/04/17 16:33:29 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ft_display_table(char **tab)
{
	int x;

	x = 0;
	while (tab[x])
	{
		if(x != 0)
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

void	ft_display_command(t_command command)
{
	ft_putstr("[");
	ft_putstr("CMD: ");

	ft_printf("<%s>", command.cmd);
	ft_putstr("][");
	ft_putstr("ARGS: ");
	ft_display_table(command.args);
	ft_putstr("]");
	ft_putstr("\n");
}

void	ft_display_command_table(t_command_table *command_table)
{
	int	i;

	if (command_table == NULL)
		return ;
	i = 0;
	ft_putstr("--- command_table_start ---\n");
	while (command_table->command_array[i].cmd != NULL)
	{
		ft_display_command(command_table->command_array[i]);
		i++;
	}
	ft_putstr("--- command_table_end ---\n");
}

void	ft_display_lexer_tokens(char **tokens_tab)
{
	int	i;

	if (tokens_tab == NULL)
		return ;
	i = 0;
	ft_putstr("--- token_table_start ---\n");
	while (tokens_tab[i]!= NULL)
	{

		ft_printf("<%s>", tokens_tab[i]);
		i++;
	}
	ft_putstr("--- token_table_end ---\n");
}

void ft_create_command_table(void)
{
	t_command_table command_table;
	t_command *command_array;

	command_table.command_array = ft_calloc(3, sizeof(t_command_table));
	command_array = command_table.command_array;
	command_array[0].cmd = ft_strdup("cmd1");
	command_array[0].args = ft_split("arg1 arg2",' ');
	command_array[1].cmd = ft_strdup("cmd2");
	command_array[1].args = ft_split("arg1 arg2",' ');
	command_array[2].cmd = NULL;
	command_array[2].args = NULL;

	ft_display_command_table(&command_table);
}

void ft_create_command_table_realistic(void)
{
	t_command_table command_table;
	t_command *command_array;

	command_table.command_array = ft_calloc(3, sizeof(t_command_table));
	command_array = command_table.command_array;
	command_array[0].cmd = ft_strdup("ls");
	command_array[0].args = ft_split("libft rendu",' ');
	command_array[1].cmd = ft_strdup("grep");
	command_array[1].args = ft_split("ft_putchar.c",' ');
	command_array[2].cmd = NULL;
	command_array[2].args = NULL;

	ft_display_command_table(&command_table);
}

