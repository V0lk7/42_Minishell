/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:15 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/26 15:51:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_exit(t_cmd *cmd)
{
	g_status = 0;
	if (cmd->cmd[1] && !ft_isdigit(cmd->cmd[1][0]))
	{
		ft_putstr_fd(2, "exit: Numeric argument required\n");
		g_status = 2;
		exit(g_status);
	}
	else if (count_args_2d(cmd->cmd) > 2)
	{
		ft_putstr_fd(2, "exit: Too many arguments\n");
		g_status = 1;
		exit(g_status);
	}
	else if (!cmd->cmd[1])
		exit(g_status);
	else
	{
		if (!ft_strncmp(cmd->cmd[1], "-1", 2))
			g_status = 255;
		else if (!ft_strncmp(cmd->cmd[1], "256", 3))
			g_status = 0;
		else
			g_status = ft_atoi(cmd->cmd[1]);
		exit(g_status);
	}
}
