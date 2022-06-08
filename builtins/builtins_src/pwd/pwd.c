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

	str = getenv("PWD");
	ft_printf("%s\n", str);
}

int	main(void)
{
	ft_display_pwd();
	return(0);
}