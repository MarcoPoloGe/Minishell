/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:43:58 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/14 13:44:00 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

char	***ft_env_expand(char **env)
{
	char	***new;
	int		i;

	if (env == NULL || *env == NULL)
		return (NULL);
	new = ft_calloc(ft_tablen(env), sizeof(char **));
	i = 0;
	while (env[i])
	{
		new[i] = ft_split(env[i], '=');
		i++;
	}
	return (new);
}

char	***ft_env_compress(char **env)
{
	char	***new;
	int		i;

	if (env == NULL || *env == NULL)
		return (NULL);
	new = ft_calloc(ft_tablen(env), sizeof(char **));
	i = 0;
	while (env[i])
	{
		new[i] = ft_split(env[i], '=');
		i++;
	}
	return (new);
}

char	***ft_read_env(void)
{
	char	***env;

	env = ft_read_two_way_tab(ENV_FILE, "txt", '=');
	if (env == NULL)
		ft_fatal_error("Can't read env file.", NULL, NULL);
	return (env);
}
