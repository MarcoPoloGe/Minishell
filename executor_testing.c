/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:38:53 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/04/27 11:59:25 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void ft_launch_app(char *program_path,char **args, char **envp)
{
	(void)envp;
	execve(program_path, args, NULL);

}

void executor()
{
	//take command table
	//fork for each pipe
	//execute command with correspondant in and out and arg modifing fd 1 and 0;
	int i;

	t_command_table commandTable;

	commandTable = ft_create_command_table();


	if(commandTable.io_in != NULL)
		ft_open();
	i = 0;
	while (commandTable.command_array[i])
	{
		if(fork() == 0)
		{

		}
		else
		{


		}
		i++;
	}




}


