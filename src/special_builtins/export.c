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
	int 	size;
	char 	*name;
	char 	*value;

	i = 1;
	while (args[i])
	{
		size = ft_strlen_char(args[i], '=');
		if (size > 0)
		{
			name = ft_strndup(args[i], size);
			if (args[i] + (size + 1))
				value = ft_strdup(args[i] + (size + 1));
			else
				value = ft_calloc(sizeof(char), 0);
		}
		else
		{
			name = ft_strdup(args[i]);
			value = NULL;
		}
		ft_modify_env(name, value);
		i++;
	}
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
