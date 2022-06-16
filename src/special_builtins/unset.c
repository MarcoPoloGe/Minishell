/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:40:45 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/13 14:40:45 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	ft_unset(int argc, char **argv)
{
	int i;
	char ***tab;

	if (argc < 2)
		return ;
	i = 1;
	tab = ft_read_env();
	while (argv[i])
		tab = ft_delete_str_tab(tab, argv[i++]);
	ft_update_env(tab);
}