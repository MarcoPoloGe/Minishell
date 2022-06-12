/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:28:40 by facolomb          #+#    #+#             */
/*   Updated: 2022/05/24 15:59:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_display_two(char **token_tab, char **ordered_token_tab)
{
	ft_putstr("\n");
	ft_putstr("token_tab :\n");
	ft_display_table(token_tab);
	ft_putstr("\n");
	ft_putstr("ordered_tab :\n");
	ft_display_table(ordered_token_tab);
	ft_putstr("\n");
	//sleep(1);
}

int ft_check_redir_has_arg(char **token_tab)
{
	int i;

	i = 0;
	while (token_tab[i])
	{
		if(ft_is_redir(token_tab[i]))
		{
			i++;
			if(token_tab[i] == NULL || ft_is_meta(token_tab[i]))
				return (1);
		}
		if(token_tab[i] != NULL)
			i++;
	}
	return (0);
}

char	**ft_lexer(char *str)
{
	char	**token_tab;

	if (str == NULL)
		return (NULL);
	token_tab = ft_build_token_tab(str);
	if(token_tab == NULL)
		return (NULL);
	if(ft_check_redir_has_arg(token_tab))
		return (ft_error("Redirection has no argument.", NULL, token_tab));
	if(ft_is_pipe(token_tab[0]))
		return (ft_error("pipe isn't a valid command start.", NULL, token_tab));
	ft_put_tokens_in_order(&token_tab);
	return (token_tab);
}

/*
char	**ft_lexer(char *str)
{
	int		i;
	int		str_len;
	char	c;
	char	*tokens;
	char	**rtn;

	i = 0;
	tokens = NULL;
	str_len = ft_strlen(str);
	while (i <= str_len)
	{
		if (str[i] == '\t' || str[i] == ' ')
			;
		else if (str[i] == '|')
			ft_stradd(&tokens, "PIPE,");
		else if (str[i] == '>')
		{
			if (str[i + 1] == '>')
			{
				ft_stradd(&tokens, "GREATGREAT,");
				i++;
			}
			else
				ft_stradd(&tokens, "GREAT,");
		}
		else if (str[i] == '<')
		{
			if (str[i + 1] == '<')
			{
				ft_stradd(&tokens, "LESSLESS,");
				i++;
			}
			else
				ft_stradd(&tokens, "LESS,");
		}
		else if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i++];
			tokens = ft_strcombine_char(tokens, c);
			while (str[i] != c)
			{
				tokens = ft_strcombine_char(tokens, str[i]);
				i++;
			}
			tokens = ft_strcombine_char(tokens, c);
			tokens = ft_strcombine_char(tokens, ',');
		}
		else if (ft_isalnum(str[i]) == 1 || str[i] == '*' || str[i] == '.' || str[i] == '_' || str[i] == '-' || str[i] == '$')
		{
			while (ft_isalnum(str[i]) == 1 || str[i] == '*' || str[i] == '.' || str[i] == '_' || str[i] == '-' || str[i] == '$')
			{
				tokens = ft_strcombine_char(tokens, str[i]);
				i++;
			}
			tokens = ft_strcombine_char(tokens, ',');
		}
		i++;
	}
	rtn = ft_split(tokens, ',');
	free(tokens);
	return (rtn);
}
*/

/*

int	main(void)
{
	char	*str = "ls -l|grep \"salut bobet\" < test.txt >> 1_A.txt\0";
	char	**rtn;
	int		i;

	i = 0;
	rtn = ft_lexer(str);
	while (rtn[i])
	{
		ft_printf("%s|", rtn[i]);	
		i++;
	}
	while (i >= 0)
	{
		free(rtn[i]);
		i--;
	}
	free(rtn);
	return(0);
}*/
