/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:15 by kramjatt          #+#    #+#             */
/*   Updated: 2023/04/04 16:03:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/parsing.h"
#include "../libft/include/libft.h"

static t_bool	non_numeric_args(const char *str)
{
	int	i;

	i = pass_whitespace(str, 0);
	while (str[i])
	{
		if (i == 0 && str[i] != '+' && str[i] != '-' && ft_isdigit(str[i]) == 0)
			return (TRUE);
		else if (i > 0 && ft_isdigit(str[i]) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static t_bool	check_overflow(const char *str)
{
	int	i;

	i = pass_whitespace(str, 0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] != '0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	ft_exit(t_cmd *cmd)
{
	long long	value;

	if (cmd->cmd[1] == NULL)
	{
		g_status = 0;
		exit(g_status);
	}
	if (non_numeric_args(cmd->cmd[1]) == TRUE)
	{
		ft_putstr_fd(2, "exit: Numeric argument required\n");
		g_status = 2;
		exit(g_status);
	}
	else if (count_args_2d(cmd->cmd) > 2)
	{
		ft_putstr_fd(2, "exit: Too many arguments\n");
		g_status = 1;
		return ;
	}
	else
	{
		value = ft_atoll(cmd->cmd[1]);
		//printf("%lli\n", value);
		if (value == 0 && check_overflow(cmd->cmd[1]) == TRUE)
		{
			ft_putstr_fd(2, "😈 Minishell 😈 : exit: ");
			ft_putstr_fd(2, cmd->cmd[1]);
			ft_putstr_fd(2, ": Numeric argument required\n");
			g_status = 2;
			exit(g_status);
		}
		else if (value == 256 || value == -256)
		{
			g_status = 0;
			exit (g_status);
		}
		else if (value > 256)
			exit(value % 256);
		else if (value < 0 && value > -256)
			exit (256 + value);
		else if (value < -256)
			exit (256 + (value % 256));
	}
}
/*
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
}*/
