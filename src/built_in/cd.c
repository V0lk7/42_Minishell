/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:28:37 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/16 11:19:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static char	*get_directory(t_mini *mini, char *str)
{
	int	i;

	i = 0;
	while (mini->envp_cpy[i])
	{
		if (!ft_strcmp(mini->envp_cpy[i], str))
			return (mini->envp_cpy[i]);
		i++;
	}
}

void	ft_cd(t_mini *mini)
{
	if (!mini->cmd[1])
	{
		mini->old_dir = mini->current_dir;
		chdir("$HOME");
		getcwd(mini->current_dir, PATH_MAX);
	}
}
