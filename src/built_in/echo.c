/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:18 by jduval            #+#    #+#             */
/*   Updated: 2023/03/13 17:43:12 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	with_flag(t_mini *mini)
{
	int	i;

	i = 1;
	while (!ft_strcmp(mini->cmd[i], "-n"))
		i++;
	while (mini->cmd[i])
	{
		ft_printf("%s", mini->cmd[i]);
		if (i != count_args_2d(mini->cmd) - 1)
			ft_putstr_fd(1, " ");
		i++;
	}
}

static void	without_flag(t_mini *mini)
{
	int	i;

	i = 1;
	while (mini->cmd[i])
	{
		ft_printf("%s", mini->cmd[i]);
		if (i != count_args_2d(mini->cmd) - 1)
			ft_putstr_fd(1, " ");
		i++;
	}	
	ft_putstr_fd(1, "\n");
}

void	ft_echo(t_mini *mini)
{
	int	i;

	i = 1;
	if (!mini->cmd[1])
	{
		ft_putstr_fd(1, "\n");
		return ;
	}
	else if (mini->cmd[1] && ft_strcmp(mini->cmd[1], "-n"))
		without_flag(mini);
	else if (mini->cmd[1] && !ft_strcmp(mini->cmd[1], "-n"))
		with_flag(mini);
}
