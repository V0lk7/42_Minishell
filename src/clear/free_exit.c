/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:05 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/13 17:56:06 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"

static void	free_tabstruct_element(t_builts *builts)
{
	int	i;

	i = -1;
	while (++i)
		free(builts[i].str);
}

void	free_exit(t_mini *mini, t_builts *builts)
{
	free_array2d(mini->cmd);
	free_array2d(mini->envp_cpy);
	free_tabstruct_element(builts);
	free(builts);
}
