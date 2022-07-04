/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:06:26 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/24 16:27:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(void)
{
	char	*input;

	input = NULL;
	while (ft_strlen(input) <= 0)
	{
		if (input)
			free(input);
		input = readline("minishell% ");
		if (input == NULL)
		{
			ft_printf("exit");
			ft_exit(0, NULL, NULL);
		}
	}
	add_history(input);
	return (input);
}
