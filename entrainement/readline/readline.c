#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
	char *str;

	str = readline("test: ");
	printf( "%s\n",str);
	return 0;
}
