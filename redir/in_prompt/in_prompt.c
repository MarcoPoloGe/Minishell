/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:24:36 by mbelarbi          #+#    #+#             */
/*   Updated: 2022/06/20 18:24:51 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/minishell.h"

char	*ft_here_doc(char *delimiter)
{
	char	*input;
	char	*here_doc;

	input = NULL;
	here_doc = NULL;
	while (!ft_str_same(input, delimiter))
	{
		ft_stradd(&here_doc, input);
		if (here_doc != NULL)
			ft_stradd(&here_doc, "\n");
		input = readline("heredoc> ");
		if (input == NULL)
		{
			//todo control D termios remove ^D
			ft_putchar('\n');
			break ;
		}
	}
	return (here_doc);
}

void	ft_in_prompt(char *delimiter)
{
	char	*here_doc;
	int		fd_in;
	int		fd_out;
	int		fd_prompt_in;
	int		fd_prompt_out;

	fd_in = dup(0);
	fd_out = dup(1);
	fd_prompt_in = open("/dev/tty", O_RDONLY);
	fd_prompt_out = open("/dev/tty", O_WRONLY);
	dup2(fd_prompt_in, 0);
	dup2(fd_prompt_out, 1);
	here_doc = ft_here_doc(delimiter);
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	if (!isatty(1))
		ft_putstr_fd(here_doc, 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr_fd("Error: more or less than one arg for "
			"redirection in_prompt.", 2);
	else
		ft_in_prompt(argv[1]);
	return (0);
}
