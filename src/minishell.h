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
	int		io_extract_fd;
	char	*io_in;
	char	*io_out;
	int		io_insert_flag;
	char	**env;
}	t_cmd_table;

//for testing (to be removed)
t_cmd_table	ft_create_cmd_table(void);
t_cmd_table	ft_create_cmd_table_realistic(void);
void		ft_exe_tester(void);

// ----- Functions -----
// --- Main ---
// --- Prompt ---
char	*ft_prompt(void);
// --- Get_cmd_path ---
char		*ft_get_cmd_path(char **env, char *name);
// --- Lexer ---
char		**ft_lexer(char *str);
// --- Parser ---
t_cmd_table	ft_parser(char **tokens, char **env);
char		*ft_check_str(char *str, char **env);
void		ft_init_table(t_cmd_table *table, int nb_cmd, char **env);
// --- Expander ---
void		ft_expander(t_cmd_table *cmd_table);
// --- Pipe ---
int			**ft_make_pipe_list(int nb);
// --- Executor ---
void		ft_executor(t_cmd_table *cmd_table);
// --- Builtins ---
void		ft_echo(char *str, int nl);
void		ft_display_env(char **env);
void		ft_display_pwd(char **env);
// --- Display ---
void		ft_display_lexer_tokens(char **tokens_tab);
void		ft_display_table(char **tab);
void		ft_display_cmd_table(t_cmd_table *cmd_table);
// --- Utils ---

#endif