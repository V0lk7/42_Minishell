/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_in_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:36:30 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 17:45:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"
#include "../libft/include/libft.h"

void	free_all(t_data *lst, t_mini *mini)
{
	free_all_nodes(&lst);
	free_array2d(mini->path);
	free_exit(mini);
}
