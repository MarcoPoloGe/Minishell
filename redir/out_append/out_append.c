/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:03:36 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/17 11:03:41 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/minishell.h"

void	ft_out_apppend(char *file_name)
{
	int		fd;
	char	*file;

	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (fd < 0)
		ft_printf_fd(2, "Error: %s: %s\n", strerror(errno), file_name);
	if (isatty(0))
		file = NULL;
	else
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
		ft_putstr_fd("Error : not one arg for redir out_append.\n", 2);
	else
		ft_out_apppend(argv[1]);
	return (0);
}
