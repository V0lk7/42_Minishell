/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:18 by jduval            #+#    #+#             */
/*   Updated: 2023/03/15 18:00:26 by kramjatt         ###   ########.fr       */
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

static void	with_flag(t_mini *mini)
{
	int	i;

	i = 2;
	while (mini->cmd[i])
	{
		ft_printf("%s", mini->cmd[i]);
		if (i != count_args_2d(mini->cmd) - 1)
			ft_putstr_fd(1, " ");
		i++;
	}
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
	else if (mini->cmd[1] && !ft_strcmp(mini->cmd[1], "-n"))
		with_flag(mini);
	else if (mini->cmd[1] && ft_strcmp(mini->cmd[1], "-n"))
	{
		if (!ft_strncmp(mini->cmd[1], "-n", 2)
			&& find_multiples_n(mini->cmd[1]))
			with_flag(mini);
		else
			without_flag(mini);
	}
	find_multiples_n(mini->cmd[1]);
}
