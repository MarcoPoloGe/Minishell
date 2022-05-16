/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelarbi@student.42lausanne.ch             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:23:54 by Marco Belarbi     #+#    #+#             */
/*   Updated: 2022/05/16 15:23:54 by Marco Belarbi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cmd_array_len(t_cmd *cmd_array)
{
	int count;

	count = 0;
	while (cmd_array[count].cmd != NULL)
		count ++;
	return count;
}
