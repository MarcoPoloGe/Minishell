/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:14:09 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/04/18 15:08:34 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <curses.h>
//#include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef struct s_command
{
	char	*cmd;
	char	**args;
}	t_command;

typedef struct s_command_table
{
	t_command	*command_array;
	char		*io_in;
	char		*io_out;
	char		*io_err;
}	t_command_table;

//for testing (to be removed)
t_command_table ft_create_command_table(void);
t_command_table ft_create_command_table_realistic(void);
void ft_launch_app(char *program_path,char **args, char **envp);

// ----- Functions -----

// --- Main ---
// --- Lexer ---
char	**ft_lexer(char *str);
// --- Parser ---
// --- Expander ---
// --- Executor ---
// --- Builtins ---
// --- Display ---
void	ft_display_lexer_tokens(char **tokens_tab);
void	ft_display_table(char **tab);
void	ft_display_command_table(t_command_table *command_table);

#endif
