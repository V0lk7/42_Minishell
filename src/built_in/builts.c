/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:11 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 17:43:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static void	init_function_array(t_builts **function)
{
	function[0] = ft_cd;
	function[1] = ft_echo;
	function[2] = ft_env;
	function[3] = ft_export;
	function[4] = ft_pwd;
	function[5] = ft_unset;
	return ;
}

void	is_built(t_cmd *cmd)
{
	t_builts	*function[6];

	if (cmd->id < 0)
		return ;
	init_function_array(function);
	function[cmd->id](cmd);
	return ;
}
