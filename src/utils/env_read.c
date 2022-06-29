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

// the function that actually stores the env table.
// It is used to read and modify the env table.
char	**ft_env(char **updated_env)
{
	static char **env;
	char *str;

	if(updated_env)
	{
		if(env)
			ft_free_tab(env);
		env = ft_tabdup(updated_env);
		str = ft_getenv("LAST_EXIT_CODE");
		if(str == NULL)
			ft_modify_env("LAST_EXIT_CODE", "0");
		else
			free(str);
	}
	if(env)
		return (env);
	else
	{
		ft_printf_fd(2, "Error : env has not been initialized");
		return (NULL);
	}
}

char	**ft_read_env(void)
{
	return (ft_tabdup(ft_env(NULL)));
}

char	*ft_getenv(char *var_name)
{
	int		i;
	char	***env;
	char	*var_content;

	var_content = NULL;
	if (var_name == NULL)
		return (NULL);
	if(ft_str_same(var_name,"?"))
		var_name = "LAST_EXIT_CODE";
	env = ft_env_expand(ft_env(NULL));
	i = 0;
	while (env[i])
	{
		if (ft_str_same(env[i][0], var_name))
			var_content = ft_strdup(env[i][1]);
		i++;
	}
	ft_free_big_tab(env);
	return (var_content);
}
