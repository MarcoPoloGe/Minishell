/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:47:57 by facolomb          #+#    #+#             */
/*   Updated: 2022/07/04 14:47:57 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void ft_enable_raw_mode(struct termios *raw)
{
	tcgetattr(STDIN_FILENO, raw);
	raw->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, raw);
}

void ft_manage_raw_mode(int to_enable)
{
	static struct termios	orig_termios;
	static struct termios	raw;

	if (!orig_termios.c_lflag)
		tcgetattr(STDIN_FILENO, &orig_termios);
	if (to_enable == 1)
		ft_enable_raw_mode(&raw);
	else
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}