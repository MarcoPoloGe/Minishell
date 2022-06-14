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
	new = ft_calloc(ft_tablen(env), sizeof(char **));
	i = 0;
	while (env[i])
	{
		new[i] = ft_split(env[i], '=');
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
	{
		ft_error("Can't open file", NULL, NULL);
		return;
	}
	while (tab[i])
	{
		write(fd, tab[i], ft_strlen(tab[i][0]));
		write(fd, "=", 1);
		write(fd, tab[i], ft_strlen(tab[i][1]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
}
char	***ft_get_env(void)
{
	char	***env;

	env = ft_read_two_way_tab(ENV_FILE, "txt", '=');
	if (env == NULL)
		ft_fatal_error("Can't read env file.", NULL, NULL);
	return (env);
}
