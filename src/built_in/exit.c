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
	cmd->mini->exit = 1;
	if (count_args_2d(cmd->cmd) > 2)
		ft_putstr_fd(2, "Too many arguments");//nexit pas et apres numeric args --> exit code 1
	else if (cmd->cmd[1] && !ft_isdigit(cmd->cmd[1][0]))
		ft_putstr_fd(2, "Numeric argument required");//avant, exit correctement exit 2
	else if (!cmd->cmd[1])
		return ;
	else
		cmd->mini->exit = ft_atoi(cmd->cmd[1]);
}
