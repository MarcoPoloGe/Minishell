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

void	ft_init_path_list(void)
{
	ft_free_tab(ft_get_paths_env(0));
}

char	**ft_get_paths_env(int do_free)
{
	static char	*absolut_path_builtin;
	char		**paths_list;
	char		*temp;

	paths_list = NULL;
	if (do_free)
	{
		free(absolut_path_builtin);
		return (NULL);
	}
	if (absolut_path_builtin == NULL)
	{
		temp = ft_strdup(BUILTIN_FOLDER);
		absolut_path_builtin = ft_strcombine(ft_getenv("PWD"), temp + 1);
		free(temp);
	}
	temp = ft_getenv("PATH");
	if (temp != NULL)
	{
		paths_list = ft_split(temp, ':');
		free(temp);
	}
	ft_tabadd_front(&paths_list, absolut_path_builtin);
	return (paths_list);
}

char	*ft_find_cmd_in_directory(char *path, char *name)
{
	DIR				*dir;
	struct dirent	*in_file;
	char			*result;

	dir = opendir(path);
	if (dir == NULL)
		ft_fatal_error("Can't read PATH folder", NULL, NULL);
	result = NULL;
	in_file = readdir(dir);
	while (in_file)
	{
		if (ft_str_same(in_file->d_name, name))
		{
			result = ft_strjoin(path, "/");
			ft_stradd(&result, name);
			break ;
		}
		in_file = readdir(dir);
	}
	closedir(dir);
	return (result);
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
char	*ft_get_cmd_path(char *name)
{
	char	**paths_list;
	char	*cmd_path;

	paths_list = ft_get_paths_env(0);
	cmd_path = ft_find_cmd_in_paths(paths_list, name);
	ft_free_tab(paths_list);
	return (cmd_path);
}
