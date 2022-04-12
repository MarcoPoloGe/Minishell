
#include "minishell.h"

int main(void)
{
	char *input;

	input = readline("minishell % ");
	printf( "%s\n",input);
	return 0;
}
