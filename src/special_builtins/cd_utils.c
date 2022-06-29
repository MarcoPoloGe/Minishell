/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:12:58 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/23 15:12:58 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

char	*ft_pwd_with_back(int nb_back, char *str, char *path)
{
	char	*tmp;
	int		nb_char;

	nb_char = ft_count_char('/', str);
	str = ft_new_str_till_n_char(nb_char - nb_back, '/', str);
	if (path[(nb_back * 3) + 1])
	{
		tmp = str;
		str = ft_strjoin(tmp, path + (nb_back * 3));
		free(tmp);
	}
	return (str);
}

char	*ft_pwd_without_back(char *str, char *path)
{
	char	*tmp;

	str = ft_getenv("PWD");
	str = ft_strcombine_char(str, '/');
	tmp = str;
	str = ft_strjoin(tmp, path);
	free(tmp);
	return (str);
}

int	ft_nb_back_path(char *path)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (path[i] && !ft_isalpha(path[i]))
	{
		if (ft_str_match(path + i, "../"))
			count++;
		i++;
	}
	return (count);
}

char	*ft_new_str_till_n_char(int n, char c, char *str)
{
	int		i;
	int		len;
	int		count;
	char	*new;

	i = 0;
	count = 0;
	while (str[i] && count <= n)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	len = i;
	i = 0;
	new = ft_calloc(sizeof(char), len);
	new[len] = '\0';
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}
