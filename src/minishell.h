/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:14:09 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/24 16:37:27 by                  ###   ########.fr       */
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
//# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

//----- Files Paths -----
# define BUILTIN_FOLDER "./builtins/bin"
# define REDIR_FOLDER "./redir/bin/"
# define META_WORDS_FILE "./config_files/meta_words.txt"
# define REDIR_WORDS_FILE "./config_files/redir_words.txt"
# define ENV_FILE "./config_files/env.txt"

//----- Special Builtins ID -----
# define BUILTIN_EXIT "exit"
# define BUILTIN_CD "cd"
# define BUILTIN_EXPORT "export"
# define BUILTIN_UNSET "unset"

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
}	t_cmd_table;

//for testing (to be removed)

// ----- Functions -----
// --- Main ---
// --- Prompt ---
char		*ft_prompt(void);
// --- Lexer ---
char		**ft_lexer(char *str);
// --- lexer_utils ---
char		**ft_build_token_tab(char *str);
char		*ft_replace_env_var(char **str);
void		ft_cmd_tokens_in_order(char ***token_tab);
void		ft_put_tokens_in_order(char ***token_tab);
// --- Parser ---
t_cmd_table	*ft_parser(char **tokens);
// --- parser_utils ---
char		*ft_check_str(char *str, char **env);
t_cmd_table	*ft_init_table(int nb_cmd);
int			ft_nb_cmd(char **tokens);
int			ft_extract_fd(char *str);
char		*ft_get_cmd_path(char *name);
char		*ft_get_redir_path(char *name);
// --- Expander ---
void		ft_expander(t_cmd_table *cmd_table);
// --- expander_utils ---
int			**ft_make_pipe_list(int nb);
// --- Executor ---
void		ft_executor(t_cmd_table *cmd_table);
// --- Builtins ---
void		ft_export(int argc, char **argv);
void		ft_unset(int argc, char **argv);
void		ft_exit(int argc, char **argv, t_cmd_table *table);
void		ft_cd(int argc, char **argv, t_cmd_table *table);
char		*ft_combine_path(int nb_back, char *s1, char *s2);
int			ft_nb_back_path(char *path);
// --- Display ---
void		ft_display_lexer_tokens(char **tokens_tab);
void		ft_display_table(char **tab);
void		ft_display_cmd_table(t_cmd_table *cmd_table);
void		ft_display_two_way_table(char ***tab);
// --- Utils ---
void		ft_free_struct(t_cmd_table **table);
int			ft_is_meta(char *input);
char		*ft_get_meta_alias(char *input);
int			ft_is_redir(char *token);
int			ft_is_redir_out(char *token);
int			ft_is_redir_in(char *token);
int			ft_is_pipe(char *token);
void		*ft_error(char *message, t_cmd_table **cmd_table, char **str_table);
void		ft_fatal_error(char *message, t_cmd_table **cmd_table,
				char **str_table);
char		**ft_env(char **updated_env);
char		**ft_read_env(void);
char		**ft_update_env(char **env);
char		***ft_env_expand(char **env);
char		**ft_env_condense(char ***env);
char		*ft_getenv(char *var_name);
int			ft_is_builtin(char *name);
//Signaux
void		signals(void);
void		signals_fork(void);
#endif