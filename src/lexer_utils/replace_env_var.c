/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:28:09 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/11 13:28:11 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_get_not_var(char *input, char **new_str)
{
	int	len;

	if (input == NULL)
		return (0);
	len = 0;
	while (input[len] && input[len] != '$')
		len++;
	ft_stradd_len(new_str, input, len);
	return (len);
}

int	ft_len_of_var(char *str)
{
	int	var_len;

	if (str == NULL)
		return (0);
	var_len = 0;
	while (str[var_len] && str[var_len] != ' ' && str[var_len] != '$')
		var_len++;
	return (var_len);
}

int	ft_get_env_var(char *str, char **new_str)
{
	char	*var_name;
	char	*var_content;
	int		var_len;

	var_name = NULL;
	if (str[0] == '$')
	{
		var_len = ft_len_of_var(str + 1);
		if (var_len <= 0)
		{
			ft_stradd(new_str, "$");
			return (1);
		}
		ft_stradd_len(&var_name, str + 1, var_len);
		var_content = ft_getenv(ft_str_to_uppercase(var_name));
		free(var_name);
		ft_stradd(new_str, var_content);
		return (var_len + 1);
	}
	return (0);
}

char	*ft_replace_env_var(char **str)
{
	int		i;
	int		var_len;
	char	*new_str;

	if (str == NULL || *str == NULL)
		return (NULL);
	new_str = NULL;
	i = 0;
	while ((*str)[i])
	{
		var_len = ft_get_env_var((*str) + i, &new_str);
		if (var_len <= 0)
			var_len = ft_get_not_var((*str) + i, &new_str);
		if (var_len <= 0)
			break ;
		i += var_len;
	}
	free((*str));
	(*str) = new_str;
	return ((*str));
}
