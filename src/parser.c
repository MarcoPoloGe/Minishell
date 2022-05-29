/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:14:10 by facolomb          #+#    #+#             */
/*   Updated: 2022/05/24 16:38:24 by                  ###   ########.fr       */
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
			table->io_insert_flag = 1;
		tmp = table->io_out;
		table->io_out = ft_strdup(file);
	}
	else
	{
		if (ft_str_same(str, "LESSLESS"))
			table->io_extract_fd = ft_extract_fd(file);
		else if (ft_str_same(str, "LESS"))
		{
			tmp = table->io_in;
			table->io_in = ft_strdup(file);
		}
	}
}

void	ft_manage_token(t_cmd_table *table, char **tokens, int *j, int i)
{
	char	*arg;

	if (ft_str_same(tokens[*j], "GREAT") || ft_str_same(tokens[*j], "LESS")
		|| ft_str_same(tokens[*j], "GREATGREAT")
		|| ft_str_same(tokens[*j], "LESSLESS"))
	{
		ft_update_io(table, tokens[*j], tokens[*j + 1]);
		(*j)++;
	}
	else
	{
		arg = ft_check_str(tokens[*j], table->env);
		ft_tabadd(&table->cmd_array[i].args, arg);
	}
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

t_cmd_table	*ft_parser(char **tokens, char **env, char *bin_folder)
{
	t_cmd_table		*table;
	int				i;
	int				j;

	i = 0;
	j = 0;
	table = ft_init_table(ft_nb_cmd(tokens), env);
	while (i < table->cmd_count)
	{
		table->cmd_array[i].cmd = ft_get_cmd_path(env, tokens[j++], bin_folder);
		if (table->cmd_array[i].cmd != NULL)
		{
			ft_tabadd(&table->cmd_array[i].args, table->cmd_array[i].cmd); //ajout de l'argv[0] pour les commandes ex pour ls = ./bin/ls.
			while (tokens[j] && !ft_str_same(tokens[j], "PIPE"))
			{
				ft_manage_token(table, tokens, &j, i);
				j++;
			}
		}
		else
			;	//TODO error incorrect cmd
		j++;
		i++;
	}
	return (table);
}
/*
int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char	**tokens;
	t_cmd_table table;
	int	i;
	int x;

	tokens = malloc(sizeof(char *) * 8);
	tokens[0] = "ls";
	tokens[1] = "-l";
	tokens[2] = "PIPE";
	tokens[3] = "grep";
	tokens[4] = "salut bobet";
	tokens[5] = "GREAT";
	tokens[6] = "test.txt";
	tokens[7] = NULL;
	table = ft_parser(tokens, env);
	i = 0;
	while(table.cmd_array[i].cmd)
	{
		ft_printf("|-------------------------------|\n");
		ft_printf("|	%s		|\n", table.cmd_array[i].cmd);
		ft_printf("|	--------ARG--------	|\n");
		x = 0;
		while (table.cmd_array[i].args[x])
		{
			ft_printf("|	%s		|\n", table.cmd_array[i].args[x]);
			x++;
		}
		i++;
	}
	ft_printf("|	--------IO--------	|\n");
	ft_printf("|	in : %s		|\n|	out : %s		|\n", table.io_in, table.io_out);
	ft_printf("|_______________________________|\n");
	while (table.env[i])
	{
		ft_printf("%s\n",table.env[i]);
		i++;
	}
	return (0);
}*/