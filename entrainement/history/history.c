#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "history.h"



int main(void)
{
	char *str;
//	readline, rl_clear_history, rl_on_new_line,
//			rl_replace_line, rl_redisplay, add_history,

	str = readline("test: ");

	rl_clear_history();
	rl_replace_line(" efsefefsf", 1);
	rl_redisplay();
	add_history("BRICE DE NICE");
	rl_redisplay();
	rl_on_new_line();



	printf( "%s\n",str);

	str = readline("test: ");
	return 0;
}
