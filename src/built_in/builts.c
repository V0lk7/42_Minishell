/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:11 by jduval            #+#    #+#             */
/*   Updated: 2023/03/16 19:56:39 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	is_built(t_mini *mini)
{
	if (!mini->cmd[0])
		return ;
	if (!ft_strcmp(mini->b_ptr[0].str, mini->cmd[0]))
		ft_cd(mini);
	if (!ft_strcmp(mini->b_ptr[1].str, mini->cmd[0]))
		ft_echo(mini);
	else if (!ft_strcmp(mini->b_ptr[2].str, mini->cmd[0]))
		ft_env(mini);
	else if (!ft_strcmp(mini->b_ptr[3].str, mini->cmd[0]))
		ft_exit(mini);
	else if (!ft_strcmp(mini->b_ptr[4].str, mini->cmd[0]))
		ft_export(mini);
	else if (!ft_strcmp(mini->b_ptr[5].str, mini->cmd[0]))
		ft_pwd(mini);
	else if (!ft_strcmp(mini->b_ptr[6].str, mini->cmd[0]))
		ft_unset(mini);
}
