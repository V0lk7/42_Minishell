/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:38 by jduval            #+#    #+#             */
/*   Updated: 2023/05/03 16:37:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"
#include <limits.h>
#include <stdio.h>

void	ft_pwd(t_cmd *cmd)
{
	char	cwd[PATH_MAX];

	g_status = 0;
	if (count_args_2d(cmd->cmd) > 1)
	{
		ft_printf("Minishell: pwd: %s : invalid option\n", cmd->cmd[1]);
		g_status = 1;
		return ;
	}
	if (!getcwd(cwd, PATH_MAX))
	{
		g_status = 1;
		return ;
	}
	ft_printf("%s\n", cwd);
}
