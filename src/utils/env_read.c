/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:45:44 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/15 13:45:47 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	***ft_read_env(void)
{
	char	***env;

	env = ft_read_two_way_tab(ENV_FILE, "txt", '=');
	if (env == NULL)
		ft_fatal_error("Can't read env file.", NULL, NULL);
	return (env);
}

char	**ft_read_env_simple(void)
{
	char	***env;
	char	**new;

	env = ft_read_env();
	new = ft_env_condense(env);
	ft_free_big_tab(env);
	return (new);
}

char	*ft_getenv(char *var_name)
{
	int		i;
	char	***env;

	if (var_name == NULL)
		return (NULL);
	env = ft_read_env();
	i = 0;
	while (env[i])
	{
		if (ft_str_same(env[i][0], var_name))
			return (env[i][1]);
		i++;
	}
	return (NULL);
}
