/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:14:10 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/28 15:14:10 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//tokens exemple : ls|PIPE|grep|"salut bobet"|LESS|test.txt|GREATGREAT|1_A.txt
//					cmd|PIPE|cmd|arg[1]|LESS|infile|GREATGREAT|outfile

void	ft_update_io(t_command_table *table, char *str, char *file)
{
	char	*tmp;

	if (ft_str_same(str, "GREAT"))
	{
		tmp = table->io_out;
		table->io_out = ft_strdup(file);
		//free(tmp);
	}
	else
	{
		tmp = table->io_in;
		table->io_in = ft_strdup(file);
		//free(tmp);
	}
}

void	ft_init_table(t_command_table *table, int nb_cmd)
{
	t_command	*cmd;
	int			i;

	i = 0;
	table->io_err = ft_calloc(8, sizeof(char));
	table->io_in = ft_calloc(8, sizeof(char));
	table->io_out = ft_calloc(8, sizeof(char));
	table->command_array = ft_calloc(nb_cmd + 1, sizeof(t_command));
	cmd = table->command_array;
	while (i <= nb_cmd)
	{
		cmd[i].args = ft_calloc(2, sizeof(char *));
		cmd[i].cmd = NULL;
		cmd[i].args[0] = NULL;
		cmd[i].args[1] = NULL;
		i++;
	}
	table->io_err = "default\0";
	table->io_in = "default\0";
	table->io_out = "default\0";
}

int	ft_nb_cmd(char **tokens)
{
	int i;

	i = 1;
	while (*tokens)
	{
		if (ft_str_same(*tokens, "PIPE"))
			i++;
		tokens++;
	}
	return (i);
}

t_command_table ft_parser(char **tokens)
{
	t_command_table table;
	int				nb_cmd;
	int				i;
	int				j;

	i = 0;
	j = 0;
	nb_cmd = ft_nb_cmd(tokens);
	ft_init_table(&table, nb_cmd);
	while(i < nb_cmd)
	{
		table.command_array[i].cmd = ft_strdup(tokens[j]);
		j++;
		while (tokens[j]  && !ft_str_same(tokens[j], "PIPE"))
		{
			if(*tokens[j] == '-')
			{
				table.command_array[i].args[0] = ft_strdup(tokens[j]);
				j++;
			}
			else if (ft_str_same(tokens[j], "GREAT") || ft_str_same(tokens[j], "LESS"))
			{
				ft_update_io(&table, tokens[j], tokens[j + 1]);
				j += 2;
			}
			else
			{
				table.command_array[i].args[1] = ft_strdup(tokens[j]);
				j++;
			}
		}
		j++;
		i++;
	}
	return(table);
}

int	main(void)
{
	char	**tokens;
	t_command_table table;
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
	while(table.command_array[i].cmd)
	{
		ft_printf("|-------------------------------|\n");
		ft_printf("|		%s		|\n", table.command_array[i].cmd);
		ft_printf("|option : %s |arg : %s	|\n", table.command_array[i].args[0],table.command_array[i].args[1]);
		i++;
	}
	ft_printf("|	--------IO--------	|\n");
	ft_printf("|	in : %s		|\n|	out : %s		|\n|	err : %s		|\n", table.io_in, table.io_out, table.io_err);
	ft_printf("|_______________________________|\n");
	return (0);
}