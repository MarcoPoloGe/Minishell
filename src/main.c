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

int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**token_tab;
	t_cmd_table *cmd_table;

	(void)argc;
	(void)argv;

	while(1)//todo temp que pas ctrl-/ ect.
	{
		input = ft_prompt();
		token_tab = ft_lexer(input, "./config_files/lexer_meta.txt");
		cmd_table = ft_parser(token_tab, env, "./builtins/bin");
		ft_expander(cmd_table);
		ft_display_cmd_table(cmd_table);
		ft_executor(cmd_table);
	}
	return (0);
}
