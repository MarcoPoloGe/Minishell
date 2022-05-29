/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:14:11 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/15 15:47:28 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_str_match(env[i], "PATH="))
			return (env[i]);
		i++;
	}
	ft_printf("error no path found");
	return (NULL);
}

char	**ft_get_paths_env(char **env)
{
	return (ft_split(ft_get_path(env) + ft_strlen("PATH="), ':'));
}

char	*ft_find_cmd_in_directory(char *path, char *name)
{
	DIR				*dir;
	struct dirent	*in_file;

	dir = opendir(path);
	in_file = readdir(dir);
	while (in_file)
	{
		if (ft_str_same(in_file->d_name, name))
		{
			path = ft_strcombine_char(ft_strdup(path), '/');
			return (ft_strcombine(path, name));
		}
		in_file = readdir(dir);
	}
	return (NULL);
}

char	*ft_find_cmd_in_paths(char **paths_list, char *name)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	while (paths_list[i] != NULL)
	{
		result = ft_find_cmd_in_directory(paths_list[i], name);
		if (result != NULL)
			return (result);
		i++;
	}
	return (NULL);
}

//si la commande n'existe pas ft_get_cmd_path retourne NULL.
char	*ft_get_cmd_path(char **env, char *name, char *builtin_folder)
{
	char	**paths_list;
	char	*cmd_path;

	paths_list = ft_get_paths_env(env);
	ft_tabadd_front(&paths_list, builtin_folder);
	cmd_path = ft_find_cmd_in_paths(paths_list, name);
	ft_free_tab(paths_list);
	return (cmd_path);
}
