/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:14:48 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/16 15:14:50 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_builtin(char *name)
{
	if (ft_str_same(name, BUILTIN_CD))
		return (1);
	if (ft_str_same(name, BUILTIN_EXIT))
		return (1);
	if (ft_str_same(name, BUILTIN_EXPORT))
		return (1);
	if (ft_str_same(name, BUILTIN_UNSET))
		return (1);
	return (0);
}
