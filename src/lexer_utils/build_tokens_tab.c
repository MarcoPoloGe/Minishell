/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:54:15 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 16:08:39 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_meta_word(char *input, char ***token_tab)
{
	int	len;

	len = ft_is_meta(input);
	if (len > 0)
	{
		ft_tabadd(token_tab, ft_get_meta_alias(input));
		return (len);
	}
	else
		return (0);
}

int	ft_get_quoted_word(char *input, char ***token_tab)
{
	int	i;

	if (input[0] != '\'' && input[0] != '\"')
		return (0);
	i = 1;
	while (input[i])
	{
		if (input[i] == input[0])
		{
			ft_tabadd_len(token_tab, input + 1, i - 1);
			if (input[0] == '\"')
				ft_replace_env_var(ft_tablast(*token_tab));
			return (i + 1);
		}
		i++;
	}
	ft_error("Quote not closed.", NULL, *token_tab);
	return (-1);
}

int	ft_get_word(char *input, char ***token_tab)
{
	int	i;

	i = 0;
	while (input[i] && !ft_isspace(input[i])
		&& input[i] != '\'' && input[i] != '\"'
		&& !ft_is_meta(input + i))
	{
		i++;
	}
	ft_tabadd_len(token_tab, input, i);
	ft_replace_env_var(ft_tablast(*token_tab));
	return (i);
}

int	ft_get_token(char *str, char ***token_tab)
{
	int		token_len;

	token_len = ft_get_meta_word(str, token_tab);
	if (token_len == 0)
	{
		token_len = ft_get_quoted_word(str, token_tab);
		if (token_len == 0)
		{
			token_len = ft_get_word(str, token_tab);
		}
	}
	return (token_len);
}

char	**ft_build_token_tab(char *str)
{
	int		old_i;
	int		i;
	int		token_len;
	char	**token_tab;

	token_tab = NULL;
	i = 0;
	while (str[i])
	{
		old_i = i;
		i = ft_skip_spaces(str, i);
		token_len = ft_get_token(str + i, &token_tab);
		if (token_tab != NULL && old_i == i)
			ft_combine_two_last(token_tab);
		if (token_len == 0)
			break ;
		if (token_len == -1)
			return (NULL);
		i += token_len;
	}
	return (token_tab);
}
