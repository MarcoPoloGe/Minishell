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

void	ft_go_to_home(void)
{
	char	*pwd;
	char	*old;

	pwd = ft_getenv("HOME");
	old = ft_getenv("PWD");
	ft_modify_env("PWD", pwd);
	ft_modify_env("OLDPWD", old);
	chdir(pwd);
	free(pwd);
	free(old);
}

void	ft_update_pwd(char *path)
{
	int		nb_back;
	char	*str;

	nb_back = ft_nb_back_path(path);
	str = ft_getenv("PWD");
	if (nb_back > 0)
		str = ft_pwd_with_back(nb_back, str, path);
	else if (ft_is_absolute(path))
		str = ft_strdup(path);
	else
		str = ft_pwd_without_back(str, path);
	if (str[ft_strlen(str) - 1] == '/')
		str[ft_strlen(str) - 1] = '\0';
	ft_modify_env("PWD", str);
	free(str);
}

void	ft_oldpwd(void)
{
	char	*str;

	str = ft_getenv("PWD");
	ft_modify_env("OLDPWD", str);
	free(str);
}

void	ft_cd(int argc, char **argv, t_cmd_table *table)
{
	DIR	*dir;

	if (argc == 2)
	{
		dir = opendir(argv[1]);
		if (!dir)
			ft_error("cd: no such file or directory", &table, NULL);
		else
		{
			ft_oldpwd();
			ft_update_pwd(argv[1]);
			chdir(argv[1]);
			closedir(dir);
		}
	}
	else if (argc > 2)
		ft_error("cd: string not in pwd", &table, NULL);
	else
		ft_go_to_home();
}
