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
	if (updated_env == NULL)
		return (NULL);
	return (ft_env(updated_env));
}

int	ft_get_position_var(char **env, char *var_name)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_str_match(env[i], var_name))
		{
			if (ft_strlen_char_end(env[i], '=') == ft_strlen(var_name))
				return (i);
		}
		i++;
	}
	return (i);
}

void	ft_modify_env(char *var_name, char *var_value)
{
	char	**env;
	int		position;

	if (var_name == NULL)
		return ;
	env = ft_read_env();
	position = ft_get_position_var(env, var_name);
	if (env[position] == NULL)
		ft_tabadd(&env, "");
	if (env[position])
		free(env[position]);
	if (var_value)
	{
		env[position] = ft_strjoin(var_name, "=");
		if (ft_strlen(var_value) == 0)
			env[position] = ft_strcombine(env[position], "\"\"");
		else
			env[position] = ft_strcombine(env[position], var_value);
	}
	else
		env[position] = ft_strdup(var_name);
	ft_update_env(env);
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

int ft_is_valid_var_env(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!(ft_isalpha(str[i])) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
