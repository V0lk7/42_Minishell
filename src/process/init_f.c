/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:35 by jduval            #+#    #+#             */
/*   Updated: 2023/05/01 18:41:50 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../libft/include/libft.h"
#include <limits.h>

void	init_minishell(t_mini *mini, char **envp)
{
	mini->current_dir = malloc(sizeof(char) * PATH_MAX);
	if (mini->current_dir == NULL)
		return ;
	getcwd(mini->current_dir, PATH_MAX);
	mini->old_dir = NULL;
	mini->envp_cpy = cpy_array2d(envp);
}
