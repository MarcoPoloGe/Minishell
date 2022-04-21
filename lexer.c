/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:28:40 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/14 15:28:40 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ft_lexer(char *str)
{
	int		i;
	int		str_len;
	char 	c;
	char	*tokens;

	i = 0;
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
			ft_stradd(&tokens, "WORD,");
			while (str[i] != c)
				i++;		
		}
		else if (ft_isalnum(str[i]) == 1 || str[i] == '*' || str[i] == '.' || str[i] == '_')
		{
			ft_stradd(&tokens, "WORD,");
			while (ft_isalnum(str[i]) == 1 || str[i] == '*' || str[i] == '.' || str[i] == '_')
				i++;
		}
		i++;
	}
	ft_printf("tokens : %s\n", tokens);
	return(NULL);
}

int	main(void)
{
	char	*str = "ls |grep \"salut bobet\" < test.txt >> 1_A.txt\0";
	char	**rtn;
	int		i;

	i = 0;
	rtn = ft_lexer(str);
	//ft_printf("%s\n", rtn[0]);
	/*while (rtn[i])
	{
		ft_printf("%s\n", rtn[i]);	
		i++;
	}*/
	return(0);
}