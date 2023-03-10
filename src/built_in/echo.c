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

#include "../../includes/minishell.h"

void	ft_echo(t_minis *minis)
{
	int	i;
	int	backslash_n;

	i = 0;
	backslash_n = 0;
	if (!minis->cmd[1])
	{
		ft_printf("\n");
		return ;
	}
	if (!ft_strcmp(minis->cmd[1], " ") && !minis->cmd[2])
		return ;
	while (minis->cmd[++i] && !ft_strcmp(minis->cmd[i], "-n"))
		backslash_n++;
	while (minis->cmd[i])
	{
		ft_printf("%s", minis->cmd[i]);
		if (minis->cmd[i + 1] && ft_strcmp(minis->cmd[i], "\0"))
			ft_printf (" ");
		i++;
	}
	ft_printf("\n");
	free_array2d(minis->cmd);
}
