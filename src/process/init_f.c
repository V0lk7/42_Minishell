/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:35 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 18:49:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"

void	init_minishell(t_mini *mini, char **envp)
{
	mini->current_dir = malloc(sizeof(char) * PATH_MAX);
	getcwd(mini->current_dir, PATH_MAX);
	mini->envp_cpy = cpy_array2d(envp);
	mini->exit = 0;
}
