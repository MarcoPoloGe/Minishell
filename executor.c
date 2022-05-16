/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_testing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:38:53 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 14:17:38 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int ft_cmd_array_len(t_cmd *cmd_array)
{
	int count;

	count = 0;
	while (cmd_array[count].cmd != NULL)
		count ++;
	return count;
}

int *ft_make_pipe(void)
{
	int *tube;

	tube = ft_calloc(2 , sizeof(int));
	if(tube == NULL)
		return (NULL);
	pipe(tube);
	return tube;
}

int **ft_make_pipe_list(int nb)
{
	int **pipe_list;
	int i;

	pipe_list = ft_calloc(nb , sizeof(int *));
	if(pipe_list == NULL)
		return (NULL);
	i = 0;

	while (i < nb - 1)
	{
		pipe_list[i] = ft_make_pipe();
		i++;
	}
	pipe_list[i] = NULL;

	return pipe_list;
}



int ft_open_io(char *io, int flags)
{
	int fd;

	if(io != NULL)
	{
		fd = open(io, flags);
		if(fd < 0)
			ft_printf("Error : file opening or creation.");
	}
	else
		return (0);
	return fd;
}

int ft_init_input(char *io_in, int io_extraction)
{
	if(io_in == NULL)
		return (0);
	if(io_extraction)
	{
		//todo not sure if extraction should happen here or in the parser.
		return (0);
	}
	else
		return (ft_open_io(io_in,O_RDONLY));
}

int ft_init_output(char *io_out, int io_insertion)
{
	if(io_out == NULL)
		return(1);
	if(io_insertion)
		return (ft_open_io(io_out,O_WRONLY | O_APPEND));
	else
		return (ft_open_io(io_out,O_WRONLY));
}

void ft_init_cmd_in_out(t_cmd_table *cmd_table)
{
	int i;
	int	**pipe_list;
	t_cmd *cmd_array;

	pipe_list = ft_make_pipe_list(cmd_table->cmd_count);
	cmd_array = cmd_table->cmd_array;

	i = 0;
	cmd_array[i].fd_in = ft_init_input(cmd_table->io_in, cmd_table->io_extraction);
	while (i < cmd_table->cmd_count - 1)
	{
		cmd_array[i].fd_out = pipe_list[i][1];
		i++;
		cmd_array[i].fd_in = pipe_list[i - 1][0];
	}
	cmd_array[i].fd_out = ft_init_output(cmd_table->io_out, cmd_table->io_insertion);
}

void ft_expander(t_cmd_table *cmd_table)
{
	//a pour but de crée les pipes et l'entrée et sortie pour les assigné a chaque process.
	ft_init_cmd_in_out(cmd_table);
}















void ft_child(t_cmd *cmd, char **env)
{
	dup2(cmd->fd_in, 0);
	dup2(cmd->fd_out, 1);

	execve(cmd->cmd, cmd->args, env);
}

void	ft_executor(t_cmd_table *cmd_table, char **env)
{
	//take cmd table
	//fork for each pipe
	//execute cmd with correspondant in and out and arg modifying fd 1 and 0;
	int	i;

	ft_init_cmd_in_out(cmd_table);
	i = 0;
	while (i < cmd_table->cmd_count)
	{
		if(fork() == 0)
		{
			ft_child((cmd_table->cmd_array + i), env);
		}
		else
		{
			wait(NULL);
			close(cmd_table->cmd_array[i].fd_out);
			close(cmd_table->cmd_array[i].fd_in);
		}
		i++;
	}
}








t_cmd_table	ft_create_cmd_table_executable(void)
{
	t_cmd_table cmd_table;
	t_cmd *cmd_array;


	cmd_table.cmd_array = ft_calloc(3, sizeof(t_cmd_table));
	cmd_table.cmd_count = 2;
	cmd_array = cmd_table.cmd_array;
	cmd_array[0].cmd = ft_strdup("philosophers");
	cmd_array[0].args = ft_split("libft rendu",' ');

	cmd_array[1].cmd = ft_strdup("philosophers");
	cmd_array[1].args = ft_split("ft_putchar.c",' ');
	cmd_array[2].cmd = NULL;
	cmd_array[2].args = NULL;

	ft_display_cmd_table(&cmd_table);
	return (cmd_table);
}

void ft_exe_tester(void)
{
	t_cmd_table cmd_table;

	cmd_table = ft_create_cmd_table_executable();

	ft_expander(&cmd_table);

	ft_executor(&cmd_table, NULL);
}





