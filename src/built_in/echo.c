/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:18 by jduval            #+#    #+#             */
/*   Updated: 2023/03/10 16:23:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_echo(t_mini *mini)
{
	int	i;
	int	backslash_n;

	i = 0;
	backslash_n = 0;
	if (!mini->cmd[1])
	{
		ft_putstr_fd(0, "\n");
		return ;
	}
	if (!ft_strcmp(mini->cmd[1], " ") && !mini->cmd[2])
		return ;
	while (mini->cmd[++i] && !ft_strcmp(mini->cmd[i], "-n"))
		backslash_n++;
	while (mini->cmd[i])
	{
		ft_printf("%s", mini->cmd[i]);
		if (mini->cmd[i + 1] && ft_strcmp(mini->cmd[i], "\0"))
			ft_putstr_fd(0, " ");
		i++;
	}
	ft_putstr_fd(0, "\n");
}
