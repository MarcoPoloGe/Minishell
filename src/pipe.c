/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:28:15 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 16:18:21 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ft_make_pipe(void)
{
	int	*tube;

	tube = ft_calloc(2, sizeof(int));
	if (tube == NULL)
		return (NULL);
	pipe(tube);
	return (tube);
}

int	**ft_make_pipe_list(int nb)
{
	int	**pipe_list;
	int	i;

	pipe_list = ft_calloc(nb, sizeof(int *));
	if (pipe_list == NULL)
		return (NULL);
	i = 0;
	while (i < nb - 1)
	{
		pipe_list[i] = ft_make_pipe();
		i++;
	}
	pipe_list[i] = NULL;
	return (pipe_list);
}
