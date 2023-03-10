/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:35 by jduval            #+#    #+#             */
/*   Updated: 2023/03/10 15:46:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_builts(t_builts *builts)
{
	builts[0].str = "cd";
	builts[1].str = "echo";
	builts[2].str = "env";
	builts[3].str = "exit";
	builts[4].str = "export";
	builts[5].str = "pwd";
	builts[6].str = "unset";
	builts[7].str = NULL;
}

void	init_minishell(t_minis *minis, t_builts *builts, char **envp)
{
	minis->envp_cpy = cpy_array2d(envp);
	minis->b_ptr = builts;
}
