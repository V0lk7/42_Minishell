/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:18 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 15:42:14 by jduval           ###   ########.fr       */
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

static void	without_flag(char *cmd)
{
	ft_printf("%s", cmd);
	ft_putstr_fd(1, "\n");
}

static void	with_flag(char	*cmd)
{
	ft_printf("%s", cmd);
}

static int	count_flags(char **cmd)
{
	int	flags;
	int	i;

	i = 1;
	flags = 0;
	while (i < count_args_2d(cmd))
	{
		if (!ft_strncmp(cmd[i], "-n", 2) && find_multiples_n(cmd[i]))
			flags++;
		else
			break ;
		i++;
	}
	return (flags);
}

void	ft_echo(t_cmd *cmd)
{
	int	i;

	i = count_flags(cmd->cmd) + 1;
	if (!cmd->cmd[1])
	{
		ft_putstr_fd(1, "\n");
		return ;
	}
	else
	{
		while (i < count_args_2d(cmd->cmd))
		{
			if (cmd->cmd[i] && !ft_strncmp(cmd->cmd[i], "$?", 2))
				ft_printf("%d\n", g_status);
			else if (count_flags(cmd->cmd))
				with_flag(cmd->cmd[i]);
			else if (!count_flags(cmd->cmd))
				without_flag(cmd->cmd[i]);
			if (i != count_args_2d(cmd->cmd) - 1)
				ft_putstr_fd(1, " ");
			i++;
		}
	}
}
