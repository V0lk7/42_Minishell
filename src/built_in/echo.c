/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:18 by jduval            #+#    #+#             */
/*   Updated: 2023/03/30 13:31:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	find_multiples_n(char *str)
{
	int	i;

	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	without_flag(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		ft_printf("%s", cmd[i]);
		if (i != count_args_2d(cmd) - 1)
			ft_putstr_fd(1, " ");
		i++;
	}	
	ft_putstr_fd(1, "\n");
}

static void	with_flag(char	**cmd)
{
	int	i;

	i = 2;
	while (cmd[i])
	{
		ft_printf("%s", cmd[i]);
		if (i != count_args_2d(cmd) - 1)
			ft_putstr_fd(1, " ");
		i++;
	}
}

void	ft_echo(t_cmd *cmd)
{
	if (!cmd->cmd[1])
	{
		ft_putstr_fd(1, "\n");
		return ;
	}
	else if (cmd->cmd[1] && !ft_strncmp(cmd->cmd[1], "$?", 2))
		ft_printf("%d\n", g_status);
	else if (cmd->cmd[1] && !ft_strcmp(cmd->cmd[1], "-n"))
		with_flag(cmd->cmd);
	else if (cmd->cmd[1] && ft_strcmp(cmd->cmd[1], "-n"))
	{
		if (!ft_strncmp(cmd->cmd[1], "-n", 2)
			&& find_multiples_n(cmd->cmd[1]))
			with_flag(cmd->cmd);
		else
			without_flag(cmd->cmd);
	}
}
