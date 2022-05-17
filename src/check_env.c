/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:26:51 by facolomb          #+#    #+#             */
/*   Updated: 2022/05/12 14:26:51 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ft_check_env(char *str, char **env, int *i)
{
	int		x;
	int		y;
	int		str_len;
	char	*tmp;
	char	*s;

	y = 0;

	str_len = 0;
	while (str[str_len + *i] != ' ')
		str_len++;
	while (env[y])
	{
		x = 0;
		while (env[y][x] != '=')
			x++;
		s = ft_strndup(env[y], x);
		if (ft_str_match(str + *i, s) && x == str_len)
		{
			tmp = s;
			s = ft_strdup(env[y] + x + 1);
			free(tmp);
			*i += x;
			return (s);
		}
		y++;
	}
	while ((ft_isalnum(str[*i]) == 1 || str[*i] == '_'))
		(*i)++;
	(*i)++;
	return (NULL);
}

char	*ft_check_str(char *str, char **env)
{
	int		i;
	char	*env_var;

	i = 0;
	env_var = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			env_var = ft_strcombine(env_var, ft_check_env(str, env, &i));
		}
		else
			env_var = ft_strcombine_char(env_var, str[i++]);
	}
	return (env_var);
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	char	*str = "test $PATH_FA bonjour";
	char	*ret;

	ret = ft_check_str(str, env);
	ft_printf("str : %s\n", ret);
	free(ret);
	return (0);
}