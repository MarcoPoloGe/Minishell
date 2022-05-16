/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:14:10 by facolomb          #+#    #+#             */
/*   Updated: 2022/05/16 15:52:56 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//tokens exemple : ls|PIPE|grep|"salut bobet"|LESS|test.txt|GREATGREAT|1_A.txt
//					cmd|PIPE|cmd|arg[1]|LESS|infile|GREATGREAT|outfile

void	ft_update_io(t_cmd_table *table, char *str, char *file)
{
	char	*tmp;

	if (ft_str_same(str, "GREAT") || ft_str_same(str, "GREATGREAT"))
	{
		if (ft_str_same(str, "GREATGREAT"))
			table->io_insertion = 1;
		tmp = table->io_out;
		table->io_out = ft_strdup(file);
	}
	else
	{
		if (ft_str_same(str, "LESSLESS"))
			table->io_extraction = 1;
		tmp = table->io_in;
		table->io_in = ft_strdup(file);
	}
}

void	ft_manage_token(t_cmd_table *table, char **tokens, int *j, int i)
{
	if (*tokens[*j] == '-')
		table->cmd_array[i].args[0] = ft_strdup(tokens[*j]);
	else if (ft_str_same(tokens[*j], "GREAT") || ft_str_same(tokens[*j], "LESS")
		|| ft_str_same(tokens[*j], "GREATGREAT")
		|| ft_str_same(tokens[*j], "LESSLESS"))
	{
		ft_update_io(table, tokens[*j], tokens[*j + 1]);
		j++;
	}
	else
		table->cmd_array[i].args[1] = ft_strdup(tokens[*j]);
}

void	ft_init_table(t_cmd_table *table, int nb_cmd)
{
	t_cmd		*cmd;
	int			i;

	i = 0;
	table->cmd_array = ft_calloc(nb_cmd + 1, sizeof(t_cmd));
	cmd = table->cmd_array;
	while (i <= nb_cmd)
	{
		cmd[i].args = ft_calloc(2, sizeof(char *));
		cmd[i].cmd = NULL;
		cmd[i].fd_in = 0;
		cmd[i].fd_out = 0;
		i++;
	}
	table->cmd_count = nb_cmd;
	table->io_in = NULL;
	table->io_out = NULL;
	table->io_extraction = 0;
	table->io_insertion = 0;
}

int	ft_nb_cmd(char **tokens)
{
	int	i;

	i = 1;
	while (*tokens)
	{
		if (ft_str_same(*tokens, "PIPE"))
			i++;
		tokens++;
	}
	return (i);
}

t_cmd_table	ft_parser(char **tokens)
{
	t_cmd_table		table;
	int				nb_cmd;
	int				i;
	int				j;

	i = 0;
	j = 0;
	nb_cmd = ft_nb_cmd(tokens);
	ft_init_table(&table, nb_cmd);
	while (i < nb_cmd)
	{
		table.cmd_array[i].cmd = ft_strdup(tokens[j++]);
		while (tokens[j] && !ft_str_same(tokens[j], "PIPE"))
		{
			ft_manage_token(&table, tokens, &j, i);
			j++;
		}
		j++;
		i++;
	}
	return (table);
}

/*
int	main(void)
{
	char	**tokens;
	t_cmd_table table;
	int	i;

	tokens = malloc(sizeof(char *) * 8);
	tokens[0] = "ls";
	tokens[1] = "-l";
	tokens[2] = "PIPE";
	tokens[3] = "grep";
	tokens[4] = "salut bobet";
	tokens[5] = "GREAT";
	tokens[6] = "test.txt";
	tokens[7] = NULL;
	table = ft_parser(tokens);
	i = 0;
	while(table.cmd_array[i].cmd)
	{
		ft_printf("|-------------------------------|\n");
		ft_printf("|		%s		|\n", table.cmd_array[i].cmd);
		ft_printf("|option : %s |arg : %s	|\n", table.cmd_array[i].args[0],table.cmd_array[i].args[1]);
		i++;
	}
	ft_printf("|	--------IO--------	|\n");
	ft_printf("|	in : %s		|\n|	out : %s		|\n|	err : %s		|\n", table.io_in, table.io_out, table.io_err);
	ft_printf("|_______________________________|\n");
	return (0);
}
*/