/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:13:41 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/02 11:13:41 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void ft_add_cmd_params(char **tokens, t_cmd_table *table, int i, int *j)
{
	ft_tabadd(&table->cmd_array[i].args, table->cmd_array[i].cmd);
	if (ft_is_redir(tokens[*j - 1]))
		if (ft_str_same(tokens[*j - 1], "LESSLESS"))
			ft_extract_fd(tokens[*j]);
		else
			ft_tabadd(&table->cmd_array[i].args, tokens[(*j)++]);
	else
	{
		while (tokens[*j] && !ft_is_redir(*tokens))
			ft_tabadd(&table->cmd_array[i].args, tokens[(*j)++]);
	}
}

int	ft_nb_cmd(char **tokens)
{
	int	i;

	i = 1;
	while (*tokens)
	{
		if (ft_is_redir(*tokens))
			i++;
		tokens++;
	}
	return (i);
}

int	ft_manage_redir(t_cmd_table *table, char **tokens, int i, int *j)
{
	if (!(ft_is_redir(tokens[++(*j)])))
	{
		ft_add_cmd_params(tokens, table, i, j);
		return (0);
	}
	else
	{
		ft_error("Redirection after redirection !!", &table);
		return (1);
	}
}

int	ft_manage_cmd(t_cmd_table *table, char **tokens, int i, int *j)
{
	if (table->cmd_array[i].cmd != NULL)
	{
		table->cmd_array[i].cmd = ft_get_cmd_path(table->env, tokens[(*j)++]);
		ft_add_cmd_params(tokens, table, i, j);
		return (0);
	}
	else
	{
		ft_error("Not a command !!", &table);
		return (1);
	}
}

t_cmd_table	*ft_new_parser(char **tokens, char **env)
{
	t_cmd_table	*table;
	int			i;
	int			j;
	int 		is_error;

	i = 0;
	j = 0;
	table = ft_init_table(ft_nb_cmd(tokens), env);
	while (i < table->cmd_count)
	{
		table->cmd_array[i].cmd = ft_get_redir_path(tokens[j]);
		if (table->cmd_array[i].cmd != NULL)
			is_error = ft_manage_redir(table, tokens, i, &j);
		else
			is_error = ft_manage_cmd(table, tokens, i ,&j);
		if (is_error == 1)
			break ;
		j++;
		i++;
	}
	return (table);
}
