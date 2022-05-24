/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:47:23 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/01/27 14:47:24 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso_marco.h"

void	ft_stradd_len(char **s1, char *s2, int s2_len)
{
	char	*old_s1;

	if (!s2)
		return ;
	old_s1 = (*s1);
	(*s1) = ft_calloc(ft_strlen(*s1) + s2_len + 1, sizeof(char));
	if ((*s1) == NULL)
		return ;
	ft_strcpy((*s1), old_s1);
	ft_strlcat((*s1), s2, s2_len);
	if (old_s1)
		free(old_s1);
}
