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

int	ft_is_token_match(char *token)
{
	int		is_match;
	char	**to_match;

	is_match = 0;
	to_match = ft_calloc(6, sizeof (char *));
	to_match[0] = ft_strdup("PIPE");
	to_match[1] = ft_strdup("GREAT");
	to_match[2] = ft_strdup("GREATGREAT");
	to_match[3] = ft_strdup("LESS");
	to_match[4] = ft_strdup("LESSLESS");
	while (*to_match)
	{
		if (ft_str_same(token, *to_match))
		{
			is_match = 1;
			break ;
		}
		to_match++;
	}
	ft_free_tab(to_match);
	return (is_match);
}

void ft_manage_fd(t_cmd_table *table, int i)
{

}

void ft_add_cmd_params(char **tokens, t_cmd_table *table, int i, int *j)
{
	ft_tabadd(&table->cmd_array[i].args, table->cmd_array[i].cmd);
	if (ft_is_token_match(tokens[*j - 1]))
		if (ft_str_same(tokens[*j - 1], "LESSLESS"))
			ft_extract_fd(tokens[*j]);
		else
			ft_tabadd(&table->cmd_array[i].args, tokens[(*j)++]);
	else
	{
		while (tokens[*j] && !ft_is_token_match(*tokens))
			ft_tabadd(&table->cmd_array[i].args, tokens[(*j)++]);
	}
	ft_manage_fd(table, i);
}

int	ft_nb_cmd(char **tokens)
{
	int	i;

	i = 1;
	while (*tokens)
	{
		if (ft_is_token_match(*tokens))
			i++;
		tokens++;
	}
	return (i);
}

t_cmd_table	*ft_new_parser(char **tokens, char **env, char *bin_folder, char *redir_folder)
{
	t_cmd_table	*table;
	int			i;
	int			j;

	i = 0;
	j = 0;
	table = ft_init_table(ft_nb_cmd(tokens), env);
	while (i < table->cmd_count)
	{
		table->cmd_array[i].cmd = ft_get_redir_path(tokens[j], redir_folder);
		if (table->cmd_array[i].cmd != NULL)
		{
			if (!(ft_is_token_match(tokens[++j])))
				ft_add_cmd_params(tokens, table, i, &j);
			else{}
				//TODO ERROR
		}
		else
		{
			table->cmd_array[i].cmd = ft_get_cmd_path(env, tokens[j++], bin_folder);
			if (table->cmd_array[i].cmd != NULL)
				ft_add_cmd_params(tokens, table, i, &j);
			else {}
			//TODO ERROR
		}
		j++;
		i++;
	}
	return (table);
}
