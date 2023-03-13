/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:18 by jduval            #+#    #+#             */
/*   Updated: 2023/03/13 16:59:56 by kramjatt         ###   ########.fr       */
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
		ft_printf(" ");
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
		ft_printf(" ");
		i++;
	}	
}

void	ft_echo(t_mini *mini)
{
	int	i;

	i = 1;
	if (!mini->cmd[1])
	{
		ft_putstr_fd(0, "\n");
		return ;
	}
	else if (mini->cmd[1] && ft_strcmp(mini->cmd[1], "-n"))
		without_flag(mini);
	else if (mini->cmd[1] && !ft_strcmp(mini->cmd[1], "-n"))
		with_flag(mini);
	ft_putstr_fd(0, "\n");
}
