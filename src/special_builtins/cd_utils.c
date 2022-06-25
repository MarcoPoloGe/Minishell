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

int	ft_nb_back_path(char *path)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (path[i])
	{
		if (ft_str_match(path + i, "../"))
			count++;
		i++;
	}
	return (count);
}

int ft_size_till_n_char(int n, char c, char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && count <= n)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (i);
}

char	*ft_combine_path(int nb_back, char *s1, char *s2)
{
	char	*new_s1;
	char	*new_s2;
	int		nb_slash_s1;
	int 	new_size;
	int 	i;

	i = 0;
	nb_slash_s1 = ft_count_char('/', s1);
	new_size = ft_size_till_n_char(nb_slash_s1 - nb_back, '/', s1);
	new_s1 = ft_calloc(sizeof(char), new_size + 1);
	while (i < new_size)
	{
		new_s1[i] = s1[i];
		i++;
	}
	new_s1[i] = '\0';
	new_s2 = ft_strdup(s2 + (nb_back * 3));
	return (ft_strcombine(new_s1, new_s2));
}
