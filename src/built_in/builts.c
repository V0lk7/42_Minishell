/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:11 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 16:34:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	init_function_array(t_builts **function)
{
	function[0] = ft_cd;
	function[1] = ft_echo;
	function[2] = ft_env;
	function[3] = ft_exit;
	function[4] = ft_export;
	function[5] = ft_pwd;
	function[6] = ft_unset;
	return ;
}

void	is_built(t_cmd *cmd)
{
	t_builts	*function[7];

	init_function_array(function);
	function[cmd->id](cmd);
	return ;
}
/*
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
}*/
