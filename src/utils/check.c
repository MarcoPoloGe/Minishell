/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:32:50 by facolomb          #+#    #+#             */
/*   Updated: 2022/07/06 15:32:50 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	ft_check_config_files(void)
{
	struct stat	buffer;

	if (stat(REDIR_WORDS_FILE, &buffer) == -1
		|| stat(META_WORDS_FILE, &buffer) == -1)
		ft_fatal_error("can't find configuration files", NULL, NULL);
}

void	ft_check_builtins(void)
{
	if (access(BUILTIN_FOLDER, F_OK))
		ft_fatal_error("builtins folder is missing", NULL, NULL);
}
