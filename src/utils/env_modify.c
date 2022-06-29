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

//Is used to update and initialize the env table.
char	**ft_update_env(char **updated_env)
{
	if(updated_env == NULL)
		return (NULL);
	return (ft_env(updated_env));
}

int ft_search_var_and_replace(char **env, char *var_name, char *var_value)
{
	int i;
	char ***big_env;
	char **updated_env;

	big_env = ft_env_expand(env);
	i = 0;
	while (env[i])
	{
		if(ft_str_same(big_env[i][0], var_name))
		{
			ft_free_tab(big_env[i]);
			big_env[i] = ft_calloc(2 + 1, sizeof (char *));
			big_env[i][0] = ft_strdup(var_name);
			if(ft_strlen(var_value) == 0 && var_value)
				big_env[i][1] = ft_strdup("\"\"");
			else
				big_env[i][1] = ft_strdup(var_value);
			updated_env = ft_env_condense(big_env);
			ft_update_env(updated_env);
			ft_free_tab(updated_env);
			ft_free_big_tab(big_env);
			return (1);
		}
		i++;
	}
	ft_free_big_tab(big_env);
	return (0);
}

void ft_modify_env(char *var_name, char *var_value)
{
	char **env;
	char *var;

	if(var_name == NULL)
		return ;
	env = ft_read_env();
	if(ft_search_var_and_replace(env, var_name, var_value) == 0)
	{
		if(var_value)
		{
			var = ft_strjoin(var_name, "=");
			if(ft_strlen(var_value) == 0)
				var = ft_strcombine(var, "\"\"");
			else
				var = ft_strcombine(var, var_value);
		}
		else
			var = ft_strdup(var_name);
		ft_tabadd(&env, var);
		free(var);
		ft_update_env(env);
	}
	ft_free_tab(env);
}

char	***ft_env_expand(char **env)
{
	char	***new;
	int		i;

	if (env == NULL || *env == NULL)
		return (NULL);
	new = ft_calloc(ft_tablen(env) + 1, sizeof(char **));
	i = 0;
	while (env[i])
	{
		new[i] = ft_split(env[i], '=');
		i++;
	}
	return (new);
}

char	**ft_env_condense(char ***env)
{
	char	**new;
	int		i;

	if (env == NULL || *env == NULL)
		return (NULL);
	new = ft_calloc(ft_big_tablen(env) + 1, sizeof(char *));
	i = 0;
	while (env[i])
	{
		if (ft_strlen(env[i][1]) > 0)
			new[i] = ft_strjoin(env[i][0], "=");
		else
			new[i] = ft_strdup(env[i][0]);
		new[i] = ft_strcombine(new[i], env[i][1]);
		i++;
	}
	return (new);
}
