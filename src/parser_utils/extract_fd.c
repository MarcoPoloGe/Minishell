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

void	ft_extract(char *str, int tube[2])
{
	char	*input;
	int 	strlen;

	input = NULL;
	while (!(ft_str_same(str, input)))
	{
		input = ft_strcombine(input, readline("extract>"));
		input = ft_strcombine_char(input, '\n');
	}
	strlen = ft_strlen(input);
	write(tube[1], input, strlen);
}

int	ft_extract_fd(char *str)
{
	int		tube[2];

	pipe(tube);
	ft_extract(str, tube);
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