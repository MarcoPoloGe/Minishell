/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tokens_in_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:24:51 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/11 14:24:52 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_len_to_token_or_end(char **token_tab, char *token)
{
	int	i;

	if (token_tab == NULL)
		return (0);
	i = 0;
	while (token_tab[i])
	{
		if (ft_str_same(token_tab[i], token))
			return (i + 1);
		i++;
	}
	return (ft_tablen(token_tab));
}

void	ft_del_chunk(char ***token_tab, int next_pipe)
{
	int	i;

	i = 0;
	while (i < next_pipe)
	{
		ft_tabdel(*token_tab, 0);
		i++;
	}
}

void	ft_put_tokens_in_order(char ***token_tab)
{
	char	**ordered_tab;
	char	**chunk_tokens;
	int		next_pipe;

	if (token_tab == NULL || *token_tab == NULL || ft_tablen(*token_tab) < 3)
		return ;
	ordered_tab = NULL;
	chunk_tokens = NULL;
	next_pipe = ft_get_len_to_token_or_end(*token_tab, "PIPE");
	while (next_pipe > 0)
	{
		chunk_tokens = ft_tabndup(*token_tab, next_pipe);
		ft_del_chunk(token_tab, next_pipe);
		ft_cmd_tokens_in_order(&chunk_tokens);
		ft_tab_combine(&ordered_tab, chunk_tokens);
		next_pipe = ft_get_len_to_token_or_end(*token_tab, "PIPE");
	}
	if (ft_tablen(*token_tab) > 0)
		ft_fatal_error("token sequence combining.", NULL, ordered_tab);
	free(*token_tab);
	*token_tab = ordered_tab;
}
