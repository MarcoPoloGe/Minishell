
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *input;
	char **token_tab;
	t_cmd_table cmd_table;

	(void)argc;
	(void)argv;

	input = readline("minishell% ");

	token_tab = ft_lexer(input);
	cmd_table = ft_parser(token_tab);
	ft_expander(&cmd_table);
	ft_executor(&cmd_table,env);

//	cmd_path =ft_get_cmd_path(env, "echo");
//	ft_printf("%s\n",cmd_path);
//	execve(cmd_path, argv, env);

	return 0;
}
