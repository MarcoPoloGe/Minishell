/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:22:03 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 16:22:34 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**token_tab;
	t_cmd_table	cmd_table;

	(void)argc;
	(void)argv;
	ft_printf("%s\n", argv[0]);
	input = readline("minishell% ");
	token_tab = ft_lexer(input);
	cmd_table = ft_parser(token_tab, env);
	ft_expander(&cmd_table);
	ft_executor(&cmd_table, env);
	/*char *cmd_path;
	cmd_path =ft_get_cmd_path(env, "ls");
	ft_printf("%s\n",cmd_path);
	execve(cmd_path, argv, env);*/
	return (0);
}
