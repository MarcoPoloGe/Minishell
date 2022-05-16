
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;

	char *cmd_path;

	cmd_path =ft_get_cmd_path(env, "echo");
	//ft_printf("%s\n",cmd_path);
	execve(cmd_path, argv, env);

	//input = readline("minishell % ");
	return 0;
}
