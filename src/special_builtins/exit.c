/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:31:57 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/09 11:31:57 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	ft_exit(int argc, char **argv, t_cmd_table *table)
{
	int	x;

	x = 0;
	if (argc <= 1)
	{
		ft_manage_raw_mode(0);
		exit(0);
	}
	else if (argc == 2)
	{
		if (ft_isalldigit(argv[1]))
			x = ft_atoi(argv[1]);
		else
		{
			ft_error("Exit : numeric argument required", NULL, NULL);
			x = 255;
		}
		if (table)
			ft_free_struct(&table);
		ft_free_statics();
		ft_manage_raw_mode(0);
		exit(x);
	}
	else if (argc > 2)
		ft_error("Exit : too many arguments", NULL, NULL);
}
