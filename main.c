
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	//char *input;

	if(argc == 3)
		ft_launch_app(argv[1], ft_split(argv[2],' '),env);
	else
		ft_putstr("wrong argv");
	//ft_create_command_table();
	//ft_create_command_table_realistic();
	//input = readline("minishell % ");
	//printf( "%s\n",input);

	return 0;
}
