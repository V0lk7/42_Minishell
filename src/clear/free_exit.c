/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:05 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/26 16:10:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"
/*
static void	free_tabstruct_element(t_builts *builts)
{
	int	i;

	i = -1;
	while (++i)
		free(builts[i].str);
}
*/
void	free_exit(t_mini *mini)
{
	free(mini->current_dir);
	free(mini->old_dir);
	free_array2d(mini->envp_cpy);
	//free_array2d(mini->cmd);
	free(mini);
	//free_tabstruct_element(builts);
	//free(builts);
}
