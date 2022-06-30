/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:22:03 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/24 16:44:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_init_prog(char **env)
{
	ft_check_config_files();
	ft_update_env(env);
	ft_init_path_list();
}

int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**token_tab;
	t_cmd_table	*cmd_table;

	(void)argc;
	(void)argv;
	ft_init_prog(env);
	while (1)
	{
		signals();
		input = NULL;
		token_tab = NULL;
		cmd_table = NULL;
		input = ft_prompt();
		token_tab = ft_lexer(input);
		if(input)
			free(input);
		cmd_table = ft_parser(token_tab);
		if(token_tab)
			ft_free_tab(token_tab);
		ft_expander(cmd_table);
		ft_executor(cmd_table);
		if(cmd_table)
			ft_free_struct(&cmd_table);
	}
}
