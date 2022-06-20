/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_trunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:24:44 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/20 18:24:49 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/minishell.h"

void	ft_out_trunc(char *str)
{
	int		fd;
	char	*file;

	fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		ft_putstr_fd("Error out_trunc: file opening or creation.", 2);
	file = ft_read_fd(0);
	if (isatty(1))
		ft_putstr_fd(file, fd);
	else
		ft_putstr_fd(file, 1);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_printf_fd(2, "Error : not one arg for redir out_append.");
	else
		ft_out_trunc(argv[1]);
	return (0);
}
