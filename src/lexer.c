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

int	ft_get_meta_word(char *input, char ***meta_word_tab, char ***token_tab)
{
	int	i;

	i = 0;
	while (meta_word_tab[i])
	{
		if (ft_str_match(input, meta_word_tab[i][0]))
		{
			ft_tabadd(token_tab, meta_word_tab[i][1]);
			return (ft_strlen(meta_word_tab[i][0]));
		}
		i++;
	}
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
			ft_tabadd_len(token_tab, input, i + 1);
			return (i + 1);
		}
		i++;
	}
	ft_printf("\nERROR quote not closed\n");
	//todo ERROR QUOTE NOT CLOSED and exit
	return (0);
}

int	ft_is_meta_word(char *input, char ***meta_word_tab)
{
	int	i;

	i = 0;
	while (meta_word_tab[i])
	{
		if (ft_str_match(input, meta_word_tab[i][0]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_word(char *input, char ***token_tab, char ***meta_word_tab)
{
	int	i;

	i = 0;
	while (input[i] && !ft_isspace(input[i])
		&& input[0] != '\'' && input[0] != '\"'
		&& !ft_is_meta_word(input + i, meta_word_tab))
	{
		i++;
	}
	ft_tabadd_len(token_tab, input, i);
	return (i);
}

char	**ft_lexer(char *str, char *lexer_meta_file)
{
	int		i;
	int		word_len;
	char	***meta_word_tab;
	char	**token_tab;

	if(str == NULL)
	{
		return(NULL); //todo error
	}

	meta_word_tab = NULL;
	token_tab = NULL;
	meta_word_tab = ft_read_two_way_tab_file(lexer_meta_file, "txt", '=');
	if(meta_word_tab == NULL)
		exit(1); //todo Error cannot read lexer_meta file;
	i = 0;
	while (str[i])
	{
		i = ft_skip_spaces(str, i);
		word_len = ft_get_meta_word((str + i), meta_word_tab, &token_tab);
		if (word_len == 0)
		{
			word_len = ft_get_quoted_word((str + i), &token_tab);
			if (word_len == 0)
			{
				word_len = ft_get_word((str + i), &token_tab, meta_word_tab);
				if (word_len == 0)
					break ;
			}
		}
		i += word_len;
	}
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
