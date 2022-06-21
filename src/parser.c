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

void	ft_add_cmd_params(char **tokens, t_cmd_table *table, int i, int *j)
{
	ft_tabadd(&table->cmd_array[i].args, table->cmd_array[i].cmd);

	if(ft_is_redir(tokens[(*j) - 1]))
	 	ft_tabadd(&table->cmd_array[i].args, tokens[(*j)++]);
	else
	{
		while (tokens[*j] && !ft_is_meta(tokens[*j]))
			ft_tabadd(&table->cmd_array[i].args, tokens[(*j)++]);
	}
}

int	ft_manage_redir(t_cmd_table *table, char **tokens, int i, int *j)
{
	if (!(ft_is_meta(tokens[++(*j)])))
	{
		ft_add_cmd_params(tokens, table, i, j);
		return (0);
	}
	else
	{
		ft_error("syntax error", &table, NULL);
		return (1);
	}
}

int	ft_manage_cmd(t_cmd_table *table, char **tokens, int i, int *j)
{
	if(ft_is_pipe(tokens[*j]))
		(*j)++;
	table->cmd_array[i].cmd = ft_get_cmd_path(tokens[*j]);
	if (table->cmd_array[i].cmd != NULL)
	{
		(*j)++;
		ft_add_cmd_params(tokens, table, i, j);
		return (0);
	}
	else if (access(tokens[*j], X_OK) == 0)
	{
		table->cmd_array[i].cmd = tokens[(*j)++];
		ft_add_cmd_params(tokens, table, i, j);
		return (0);
	}
	else
	{
		ft_error("Command not found", &table, NULL);
		return (1);
	}
}

void	ft_manage_builtins(t_cmd_table *table, char **tokens, int i, int *j)
{
	table->cmd_array[i].cmd = ft_strdup(tokens[*j]);
	(*j)++;
	ft_add_cmd_params(tokens, table, i, j);
}

t_cmd_table	*ft_parser(char **tokens)
{
	t_cmd_table	*table;
	int			i;
	int			j;
	int			is_error;

	i = 0;
	j = 0;
	if (!tokens)
		return (NULL);
	table = ft_init_table(ft_nb_cmd(tokens));
	while (i < table->cmd_count)
	{
		table->cmd_array[i].cmd = ft_get_redir_path(tokens[j]);
		if (table->cmd_array[i].cmd != NULL)
			is_error = ft_manage_redir(table, tokens, i, &j);
		else if (ft_is_builtin(tokens[j]) == 1)
			ft_manage_builtins(table, tokens, i, &j);
		else
			is_error = ft_manage_cmd(table, tokens, i, &j);
		if (is_error == 1)
			return (NULL);
		i++;
		//j++;
	}
	return (table);
}
