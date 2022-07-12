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

void	ft_combine_two_last(char **token_tab)
{
	char	*temp;
	int		i;

	if (ft_tablen(token_tab) < 2)
		return ;
	i = 0;
	while (token_tab[i + 2] != NULL)
		i++;
	if (ft_is_meta(token_tab[i]) || ft_is_meta(token_tab[i + 1]))
		return ;
	temp = ft_strdup(token_tab[i]);
	free(token_tab[i]);
	token_tab[i] = ft_strcombine(temp, token_tab[i + 1]);
	free(token_tab[i + 1]);
	token_tab[i + 1] = NULL;
}
