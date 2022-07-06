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
	(void) argv;
	if (argc != 1)
		ft_printf_fd(2, "Error : Too many arguments for builtin pwd\n");
	else
		ft_display_pwd(env);
	return (0);
}