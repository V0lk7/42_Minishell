/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:18 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 17:37:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"

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

static void	without_flag(char **cmd, int i)
{
	ft_printf("%s", cmd[i]);
	if (cmd[i + 1] == NULL)
		ft_printf("\n");
}

static int	count_flags(char **cmd)
{
	int	flags;
	int	i;

	i = 1;
	flags = 0;
	while (cmd[i])
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
	while (cmd->cmd[i])
	{
		if (count_flags(cmd->cmd))
			ft_printf("%s", cmd->cmd[i]);
		else if (!count_flags(cmd->cmd))
			without_flag(cmd->cmd, i);
		i++;
		if (i < count_args_2d(cmd->cmd))
			ft_printf(" ");
	}
	g_status = 0;
	return ;
}
