
#include "minishell.h"

int main(void)
{
	char *input;

	ft_create_command_table();
	ft_create_command_table_realistic();
	input = readline("minishell % ");
	printf( "%s\n",input);

	return 0;
}
