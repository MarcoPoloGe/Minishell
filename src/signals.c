/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:37:00 by facolomb          #+#    #+#             */
/*   Updated: 2022/06/22 11:37:00 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	sig_fork_handler_int(int sig)
{
	ft_printf("\n");
	ft_modify_env("LAST_EXIT_CODE", "130");
	(void) sig;
}

void	sig_fork_handler_quit(int sig)
{
	ft_printf("Quit : %d\n", sig);
	ft_modify_env("LAST_EXIT_CODE", "131");
}

void	sig_handler_int(int sig)
{
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void) sig;
}

void	signals_fork(void)
{
	signal(SIGINT, sig_fork_handler_int);
	signal(SIGQUIT, sig_fork_handler_quit);
}

void	signals(void)
{
	signal(SIGINT, sig_handler_int);
	signal(SIGQUIT, SIG_IGN);
}
