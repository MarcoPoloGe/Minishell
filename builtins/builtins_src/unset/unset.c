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
#include "../../../src/minishell.h"

void	ft_unset(char **args)
{
	int i;
	char ***tab;

	i = 1;
	tab = ft_get_env();
	while (args[i])
		tab = ft_delete_str_tab(tab, args[i++]);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		ft_unset(argv);
	return (0);
}