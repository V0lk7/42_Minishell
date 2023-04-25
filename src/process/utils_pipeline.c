/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:46:11 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 18:19:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/built_in.h"
#include "../../includes/clear.h"
#include <stdlib.h>

void	chose_builtin_or_exec(t_data *tmp, t_data *lst, t_mini *mini)
{
	if (tmp->data.cmd.id >= 0 && tmp->data.cmd.id != 3)
	{
		is_built(&tmp->data.cmd);
		free_all(lst, mini);
		exit (g_status);
	}
	else if (tmp->data.cmd.id == 3)
	{
		ft_exit(&tmp->data.cmd, lst, mini);
		exit(g_status);
	}
	g_status = exec_utils(tmp, mini);
}
