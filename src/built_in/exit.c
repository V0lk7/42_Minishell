/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:15 by kramjatt          #+#    #+#             */
/*   Updated: 2023/04/07 13:41:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../../includes/utils.h"
#include "../../includes/clear.h"
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

static t_bool	syntax_error_exit(char **cmd)
{
	if (cmd[1] == NULL)
	{
		g_status = 0;
		return (TRUE);
	}
	if (non_numeric_args(cmd[1]) == TRUE)
	{
		ft_putstr_fd(2, "exit: Numeric argument required\n");
		g_status = 2;
		return (TRUE);
	}
	else if (count_args_2d(cmd) > 2)
	{
		ft_putstr_fd(2, "exit: Too many arguments\n");
		g_status = 1;
		return (TRUE);
	}
	return (FALSE);
}

static int	exit_status(long long value, char *str)
{
	if (value == 0 && check_overflow(str) == TRUE)
	{
		error_exit(str);
		return (2);
	}
	else if (value == 256 || value == -256)
	{
		g_status = 0;
		return (0);
	}
	else if (value > 256)
		return (value % 256);
	else if (value < 0 && value > -256)
		return (256 + value);
	else if (value < -256)
		return (256 + (value % 256));
	else
		return (value);
}

void	ft_exit(t_cmd *cmd, t_data *lst, t_mini *mini)
{
	long long	value;

	if (syntax_error_exit(cmd->cmd) == TRUE)
	{
		free_all(lst, mini);
		exit (g_status);
	}
	value = ft_atoll(cmd->cmd[1]);
	g_status = exit_status(value, cmd->cmd[1]);
	free_all(lst, mini);
	exit (g_status);
}
