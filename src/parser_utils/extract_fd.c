/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:01:59 by facolomb          #+#    #+#             */
/*   Updated: 2022/05/24 15:12:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_extract_fd(char *str)
{
	int		tube[2];
    int		strlen;

	pipe(tube);
	strlen = ft_strlen(str) + 1;
	write(tube[1], str, strlen);
	close(tube[1]);
	return (tube[0]);
}
/*
int	main(void)
{
	int fd;
	char buff[8];

	fd = ft_extract_fd("bonjour");
	ft_printf("fd : %d\n", fd);
	read(fd, buff, 7);
	write(1, &buff, 7);
	return (0);
}*/