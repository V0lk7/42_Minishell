/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:56:05 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/01 18:42:05 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../libft/include/libft.h"

void	free_exit(t_mini *mini)
{
	free(mini->current_dir);
	if (mini->old_dir)
		free(mini->old_dir);
	free_array2d(mini->envp_cpy);
}
