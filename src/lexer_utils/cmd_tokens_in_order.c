/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tokens_in_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:22:12 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/11 14:22:14 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_move_all_not_redir(char ***token_tab, char ***ordered_token_tab)
{
	int	i;

	if (token_tab == NULL || *token_tab == NULL)
		return ;
	i = 0;
	while ((*token_tab)[i])
	{
		if (ft_is_redir((*token_tab)[i]))
		{
			i++;
			if ((*token_tab)[i] != NULL)
				i++;
		}
		else
		{
			ft_tabadd(ordered_token_tab, (*token_tab)[i]);
			ft_tabdel(*token_tab, i);
		}
	}
}

void	ft_move_redir_in(char ***token_tab, char ***ordered_token_tab)
{
	int	i;

	i = ft_tablen(*token_tab) - 1;
	while (i >= 0)
	{
		if (ft_is_redir_in((*token_tab)[i]))
		{
			ft_tabadd_front(ordered_token_tab, (*token_tab)[i + 1]);
			ft_tabdel(*token_tab, i + 1);
			ft_tabadd_front(ordered_token_tab, (*token_tab)[i]);
			ft_tabdel(*token_tab, i);
		}
		else
		{
			i--;
		}
	}
}

void	ft_move_redir_out(char ***token_tab, char ***ordered_token_tab)
{
	int	i;

	i = 0;
	while ((*token_tab)[i])
	{
		if (ft_is_redir_out((*token_tab)[i]))
		{
			ft_tabadd(ordered_token_tab, (*token_tab)[i]);
			ft_tabdel(*token_tab, i);
			ft_tabadd(ordered_token_tab, (*token_tab)[i]);
			ft_tabdel(*token_tab, i);
		}
		else
		{
			i++;
		}
	}
}

void	ft_move_pipe_to_last(char ***ordered_token_tab)
{
	int	i;

	if (ordered_token_tab == NULL || *ordered_token_tab == NULL)
		return ;
	i = 0;
	while ((*ordered_token_tab)[i])
	{
		if (ft_is_pipe((*ordered_token_tab)[i]))
		{
			ft_tabdel((*ordered_token_tab), i);
			ft_tabadd(ordered_token_tab, "PIPE");
			break ;
		}
		i++;
	}
}

void	ft_cmd_tokens_in_order(char ***token_tab)
{
	char	**ordered_token_tab;

	if (token_tab == NULL || *token_tab == NULL || ft_tablen(*token_tab) < 3)
		return ;
	ordered_token_tab = NULL;
	ft_move_all_not_redir(token_tab, &ordered_token_tab);
	ft_move_redir_in(token_tab, &ordered_token_tab);
	ft_move_redir_out(token_tab, &ordered_token_tab);
	ft_move_pipe_to_last(&ordered_token_tab);
	if (ft_tablen(*token_tab) > 0)
		ft_fatal_error("Not every token is taken care of.", NULL, *token_tab);
	if (*token_tab)
		ft_free_tab(*token_tab);
	*token_tab = ordered_token_tab;
}
