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
#include "../minishell.h"

void	ft_add_export(char **args)
{
	int		i;
	char	**env;

	i = 1;
	env = ft_read_env();
	while (args[i])
	{
		if (ft_isalpha(args[i][0]) || args[i][0] == '_')
			ft_tabadd(&env, args[i]);
		else
			ft_error("export, not a valid identifier ", NULL, NULL);
		i++;
	}
	ft_update_env(env);
	ft_free_tab(env);
}

void	ft_display_export(void)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_read_env();
	tab = ft_sort_str_tab(tab);
	while (tab[i])
		ft_printf("declare -x %s\n", tab[i++]);
	ft_free_tab(tab);
}

void	ft_export(int argc, char **argv)
{
	if (argc == 1)
		ft_display_export();
	else
		ft_add_export(argv);
}
