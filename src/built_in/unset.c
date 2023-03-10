/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:10 by jduval            #+#    #+#             */
/*   Updated: 2023/03/10 15:46:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		if (i == unset)
			i++;
		array[j] = malloc(sizeof(char) * ft_strlen(envp_cpy[i]) + 1);
		ft_strcpy(array[j], envp_cpy[i]);
		i++;
		j++;
	}
	return (array);
}

void	ft_unset(t_minis *minis)
{
	int		i;
	int		length;

	i = 0;
	length = count_args_2d(minis->cmd);
	if (length != 2 || !minis->cmd[0] || !minis->cmd[1])
		return ;
	while (ft_strncmp(minis->cmd[1], minis->envp_cpy[i],
			ft_strlen(minis->cmd[1])))
		i++;
	minis->envp_cpy = realloc_unset(minis->envp_cpy, i);
}
