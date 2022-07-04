/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:18:40 by facolomb          #+#    #+#             */
/*   Updated: 2022/07/04 16:18:40 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "perso_fabian.h"

int	ft_is_dir(char *path)
{
	struct stat	status;

	if (stat(path, &status) != 0)
		return (0);
	return (S_ISDIR(status.st_mode));
}
