/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:03:32 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/20 18:27:52 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/minishell.h"

void	ft_in_file(char *str)
{
	char	*file;

	file = ft_read_file(str, NULL);
	if (file == NULL)
		return ;
	if (!isatty(1))
		ft_putstr_fd(file, 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd("Error: more or less than one arg for "
			"redirection in_file.\n", 2);
	else
		ft_in_file(argv[1]);
	return (0);
}
