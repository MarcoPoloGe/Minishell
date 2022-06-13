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
#include "../../../src/minishell.h"

void	ft_display_pwd(void)
{
	char	*str;

	str = getenv(str);
	ft_printf("%s\n", str);
}

int	main(int argc, char **argv)
{
	(void) argv;

	if (argc != 2)
		ft_printf("Too many arguments !\n");
	else
		ft_display_pwd();
	return(0);
}