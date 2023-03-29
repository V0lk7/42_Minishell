/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:10 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 15:59:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static char	**realloc_unset(char **envp_cpy, int unset)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	array = malloc(sizeof(char *) * count_args_2d(envp_cpy));
	while (envp_cpy[i])
	{
		if (i == unset && unset == count_args_2d(envp_cpy) - 1)
			break ;
		if (i == unset)
			i++;
		array[j] = malloc(sizeof(char) * ft_strlen(envp_cpy[i]) + 1);
		ft_strcpy(array[j], envp_cpy[i]);
		i++;
		j++;
	}
	array[j] = NULL;
	return (array);
}

void	ft_unset(t_cmd *cmd)
{
	int		i;
	int		length;

	i = 0;
	length = count_args_2d(cmd->cmd);
	if (length != 2 || !cmd->cmd[0] || !cmd->cmd[1])
		return ;
	while (cmd->mini->envp_cpy[i]
		&& ft_strncmp(cmd->cmd[1], cmd->mini->envp_cpy[i],
			ft_strlen(cmd->cmd[1])))
		i++;
	if (!cmd->mini->envp_cpy[i])
		return ;
	cmd->mini->envp_cpy = realloc_unset(cmd->mini->envp_cpy, i);
}
