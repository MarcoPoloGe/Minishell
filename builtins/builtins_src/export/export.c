/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:08:36 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/09 15:08:36 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../src/minishell.h"

void	ft_add_export(char **args)
{
	int i;
	char ***tab;

	i = 1;
	tab = ft_get_env();
	while (args[i])
	{
		if (ft_isalpha(args[i][0]))
			ft_tabadd(tab, args[i]);
		else
			ft_error("export, not a valid identifier ", NULL, NULL);
		i++;
	}
	ft_update_env(tab);
}

void	ft_display_export()
{
	int i;
	char ***tab;

	i = 0;
	tab = ft_get_env();
	tab = ft_sort_str_tab(tab);
	while (tab[i])
		ft_printf("declare -x %s=%s\n", tab[i][0], tab[i][1]);
}

int main(int argc, char **argv)
{
	(void) argc;

	if (!argv)
		ft_display_export();
	else
		ft_add_export(argv);
}