/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:38 by jduval            #+#    #+#             */
/*   Updated: 2023/03/10 15:46:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(t_minis *minis)
{
	char	cwd[PATH_MAX];

	(void)minis;
	if (!getcwd(cwd, PATH_MAX))
	{
		perror("Error getcwd ");
		return ;
	}
	printf("%s\n", cwd);
}
