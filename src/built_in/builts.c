/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:11 by jduval            #+#    #+#             */
/*   Updated: 2023/03/10 15:45:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_built(t_minis *minis)
{
	if (!minis->cmd[0])
		return ;
	if (!strcmp(minis->b_ptr[1].str, minis->cmd[0]))
		ft_echo(minis);
	else if (!strcmp(minis->b_ptr[2].str, minis->cmd[0]))
		ft_env(minis);
	else if (!strcmp(minis->b_ptr[5].str, minis->cmd[0]))
		ft_pwd(minis);
	else if (!strcmp(minis->b_ptr[6].str, minis->cmd[0]))
		ft_unset(minis);
}
