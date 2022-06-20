/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:01:10 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/12 13:01:12 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	***ft_get_meta_word_tab(void)
{
	static char	***meta_word_tab;

	if (meta_word_tab == NULL)
		meta_word_tab = ft_read_two_way_tab(META_WORDS_FILE, "txt", '=');
	if (meta_word_tab == NULL)
		ft_fatal_error("Cannot read meta_words.txt", NULL, NULL);
	return (meta_word_tab);
}

//returns the alias of any meta_word ex : > = GREAT
char	*ft_get_meta_alias(char *input)
{
	int		i;
	char	***meta_word_tab;

	meta_word_tab = ft_get_meta_word_tab();
	if (input == NULL)
		return (NULL);
	i = 0;
	while (meta_word_tab[i])
	{
		if (ft_str_match(input, meta_word_tab[i][0]))
			return (meta_word_tab[i][1]);
		i++;
	}
	return (NULL);
}

// if input is a meta_word it returns the len of the meta_word.
// works with the original word and alias.
int	ft_is_meta(char *input)
{
	int		i;
	int		column;
	char	***meta_word_tab;

	if (input == NULL)
		return (0);
	meta_word_tab = ft_get_meta_word_tab();
	column = 0;
	i = 0;
	while (column <= 1)
	{
		while (meta_word_tab[i])
		{
			if (ft_str_match(input, meta_word_tab[i][column]))
				return (ft_strlen(meta_word_tab[i][column]));
			i++;
		}
		i = 0;
		column++;
	}
	return (0);
}
