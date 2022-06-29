/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:14:01 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/20 18:14:03 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	ft_oldpwd(void)
{
	char **env;
	char *old;

	env = ft_read_env();
	old = ft_getenv("PWD");
	old = ft_strjoin("OLDPWD=", old);
	ft_tabadd(&env, old);
	ft_update_env(env);
	ft_free_tab(env);
	free(old);
}

void	ft_update_pwd(char *path, int is_home)
{
	char **env;
	int i;

	i = 0;
	env = ft_read_env();
	while (env[i] && !ft_str_match(env[i], "PWD"))
		i++;
	if (is_home == 1)
		env[i] = ft_strjoin("PWD=", path);
	else
		env[i] = ft_combine_path(ft_nb_back_path(path), env[i], path);
	ft_update_env(env);
	ft_free_tab(env);
}

void	ft_go_to_home(void)
{
	char	*home;

	ft_oldpwd();
	home = ft_getenv("HOME");
	ft_update_pwd(home, 1);
	chdir(home);
}

void	ft_cd(int argc, char **argv, t_cmd_table *table)
{
	DIR *dir;

	if (argc == 2)
	{
		dir = opendir(argv[1]);
		if (!dir)
			ft_error("cd: no such file or directory", &table, NULL);
		else
		{
			ft_oldpwd();
			ft_update_pwd(argv[1], 0);
			chdir(argv[1]);
		}
		closedir(dir);
	}
	else if (argc > 2)
		ft_error("cd: string not in pwd", &table, NULL);
	else
		ft_go_to_home();
}
