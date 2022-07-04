/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:23:54 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/06/12 13:01:19 by mbelarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_check_config_files(void)
{
	struct stat	buffer;

	if (stat(REDIR_WORDS_FILE, &buffer) == -1
		|| stat(META_WORDS_FILE, &buffer) == -1)
		ft_fatal_error("can't find configuration files", NULL, NULL);
}

void	ft_free_struct(t_cmd_table **table_adress)
{
	t_cmd_table	*table;
	int			i;

	if (table_adress == NULL || *table_adress == NULL)
		return ;
	table = *table_adress;
	i = 0;
	while (table->cmd_array[i].cmd)
	{
		free(table->cmd_array[i].cmd);
		if (table->cmd_array[i].args)
			ft_free_tab(table->cmd_array[i].args);
		i++;
	}
	free(table->cmd_array);
	free(table);
	*table_adress = NULL;
}

void ft_free_statics(void)
{
	ft_free_tab(ft_env(NULL));
	ft_free_tab(ft_get_paths_env());
	ft_free_big_tab(ft_get_redir_word_tab());
	ft_free_big_tab(ft_get_meta_word_tab());
}

void	*ft_error(char *message, t_cmd_table **cmd_table, char **str_table)
{
	ft_printf_fd(2, "Error : %s\n", message);
	ft_free_struct(cmd_table);
	ft_free_tab(str_table);
	return (NULL);
}

void	ft_fatal_error(char *message, t_cmd_table **cmd_table, char **str_table)
{
	ft_printf_fd(2, "Fatal Error : %s\n", message);
	ft_free_struct(cmd_table);
	ft_free_tab(str_table);
	ft_free_statics();
	exit(1);
}
