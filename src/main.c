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

	ft_init_env(env);
	while(1)//todo temp que pas ctrl-/ ect.
	{
		input = ft_prompt();
		token_tab = ft_lexer(input);
		cmd_table = ft_parser(token_tab);
		ft_expander(cmd_table);
		//ft_display_cmd_table(cmd_table);
		ft_executor(cmd_table);
	}
	return (0);
}

//
//int	main(int argc, char **argv, char **env)
//{
//	/*char		*input;
//	char		**token_tab;
//	t_cmd_table *cmd_table;*/
//
//	(void)argc;
//	(void)argv;
//
//	ft_init_env(env);
//	char **en2;
//
//	en2 = ft_read_env_simple();
//
//	ft_tabadd(&en2, "lol=test");
//	ft_tabadd(&en2, "super=effef");
//
//	ft_update_env_simple(en2);
//	ft_display_big_tab(ft_read_env());
//	/*while(1)//todo temp que pas ctrl-/ ect.
//	{
//		input = ft_prompt();
//		token_tab = ft_lexer(input);
//		cmd_table = ft_parser(token_tab, env);
//		ft_expander(cmd_table);
//		//ft_display_cmd_table(cmd_table);
//		ft_executor(cmd_table);
//	}*/
//	return (0);
//}