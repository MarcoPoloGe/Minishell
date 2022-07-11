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
	char	**env;
	int		i;

	if (argc < 2)
		return ;
	i = 1;
	while (argv[i])
	{
		if (ft_is_valid_var_env(argv[i]))
		{
			env = ft_read_env();
			env = ft_delete_str_tab(env, argv[i]);
			ft_update_env(env);
			ft_free_tab(env);
		}
		else
		{
			ft_error("Unset : not a valid identifier", NULL, NULL);
			break ;
		}
		i++;
	}
}
