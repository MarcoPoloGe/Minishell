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

void	ft_cd(int argc, char **argv)
{
	DIR	*dir;

	if (argc >= 2)
	{
		dir = opendir(argv[1]);
		if (!dir)
		{
			ft_error("cd: no such file or directory", NULL, NULL);
			ft_modify_env("LAST_EXIT_CODE", "1");
		}
		else
		{
			if (!ft_str_same(".", argv[1]) && !ft_str_same("./", argv[1]))
			{
				ft_oldpwd();
				ft_update_pwd(argv[1]);
				chdir(argv[1]);
			}
			else
				ft_oldpwd();
			closedir(dir);
		}
	}
	else
		ft_go_to_home();
}
