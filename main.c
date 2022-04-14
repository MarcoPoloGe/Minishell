
#include "minishell.h"

int main(void)
{
	char ***tab_test;
	tab_test = malloc(sizeof (char **) * 3);
	tab_test[0] = ft_split("case1 case2",' ');
	tab_test[1] = ft_split("case3 case4",' ');
	tab_test[2] = NULL;
	ft_display_two_way_table(tab_test, 20);

	char *input;

	input = readline("minishell % ");
	printf( "%s\n",input);


	return 0;
}
