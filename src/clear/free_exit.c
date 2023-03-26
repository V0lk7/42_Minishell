/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:05 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/26 18:57:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"

void	free_exit(t_mini *mini)
{
	free(mini->current_dir);
	//free(mini->old_dir);
	free_array2d(mini->envp_cpy);
	//free(mini);
}
