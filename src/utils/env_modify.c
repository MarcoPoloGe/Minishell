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
		new[i] = ft_strjoin(env[i][0],"=");
		new[i] = ft_strcombine(new[i],env[i][1]);
		i++;
	}
	return (new);
}

void	ft_update_env(char ***tab)
{
	int fd;
	int i;

	i = 0;
	fd = open(ENV_FILE, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		ft_fatal_error("Can't open file", NULL, NULL);
	while (tab[i])
	{
		ft_putstr_fd(tab[i][0],fd);
		ft_putchar_fd('=',fd);
		ft_putstr_fd(tab[i][1],fd);
		ft_putchar_fd('\n',fd);
		i++;
	}
	close(fd);
}

void ft_init_env(char **env)
{
	char	***new;

	new = ft_env_expand(env);
	ft_update_env(new);
}

void	ft_update_env_simple(char **env)
{
	char	***new;

	new = ft_env_expand(env);
	ft_update_env(new);
	ft_free_big_tab(new);
}









