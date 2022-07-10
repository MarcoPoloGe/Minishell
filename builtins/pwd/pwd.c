/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:33:08 by facolomb          #+#    #+#             */
/*   Updated: 2022/04/28 14:33:08 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_is_option(char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

void	ft_display_pwd(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_str_match(env[i], "PWD"))
			ft_printf("%s\n", env[i] + 4);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	is_option;

	(void) argv;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			is_option = ft_is_option(argv[i]);
			if (is_option == 1)
				break ;
			i++;
		}
		if (!is_option)
			ft_display_pwd(env);
		else
			ft_printf_fd(2, "Error : PWD : invalid option\n");
	}
	else
		ft_display_pwd(env);
	return (0);
}
