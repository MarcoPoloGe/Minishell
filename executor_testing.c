/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:38:53 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/04/18 15:19:15 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void ft_launch_app(char *program_path,char **args, char **envp)
{
	(void)envp;
//	int execve(const char *pathname, char const **argv,
//			   char const **envp);

	execve(program_path, args, NULL);

}
