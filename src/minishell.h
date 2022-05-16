/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:14:09 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 16:20:56 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <curses.h>
# include <dirent.h>
//#include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef struct s_cmd
{
	int		fd_in;
	char	*cmd;
	char	**args;
	int		fd_out;
}	t_cmd;

typedef struct s_cmd_table
{
	t_cmd	*cmd_array;
	int		cmd_count;
	int		io_extraction;
	char	*io_in;
	char	*io_out;
	int		io_insertion;
}	t_cmd_table;

//for testing (to be removed)
t_cmd_table	ft_create_cmd_table(void);
t_cmd_table	ft_create_cmd_table_realistic(void);
void		ft_exe_tester(void);

// ----- Functions -----
// --- Main ---
// --- Get_cmd_path ---
char		*ft_get_cmd_path(char **env, char *name);
// --- Lexer ---
char		**ft_lexer(char *str);
// --- Parser ---
t_cmd_table	ft_parser(char **tokens);
// --- Expander ---
void		ft_expander(t_cmd_table *cmd_table);
// --- Pipe ---
int			**ft_make_pipe_list(int nb);
// --- Executor ---
void		ft_executor(t_cmd_table *cmd_table, char **env);
// --- Builtins ---
void		ft_echo(char *str, int nl, char **env);
void		ft_display_env(char **env);
void		ft_display_pwd(char **env);
// --- Display ---
void		ft_display_lexer_tokens(char **tokens_tab);
void		ft_display_table(char **tab);
void		ft_display_cmd_table(t_cmd_table *cmd_table);
// --- Utils ---
int			ft_cmd_array_len(t_cmd *cmd_array);

#endif