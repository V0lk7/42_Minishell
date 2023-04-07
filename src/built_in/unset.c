/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:10 by jduval            #+#    #+#             */
/*   Updated: 2023/04/07 18:09:04 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"

static char	**realloc_unset(char **envp_cpy, int unset)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	array = malloc(sizeof(char *) * count_args_2d(envp_cpy) + 1);
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
	free_array2d(envp_cpy);
	return (array);
}

static t_bool	find_variable(char *str, char *cmd)
{
	int	equal;
	int	len;

	equal = search_c(str, '=');
	len = (int)ft_strlen(cmd);
	if (equal < 0)
	{
		if (len != (int)ft_strlen(str))
			return (FALSE);
		else if (ft_strncmp(str, cmd, len) == 0)
			return (TRUE);
		return (FALSE);
	}
	if (len != equal)
		return (FALSE);
	if (ft_strncmp(str, cmd, len) == 0)
		return (TRUE);
	return (FALSE);
}

void	ft_unset(t_cmd *cmd)
{
	int		i;
	int		length;

	i = 0;
	length = count_args_2d(cmd->cmd);
	if (length != 2 || !cmd->cmd[0] || !cmd->cmd[1])
		return ;
	while (cmd->mini->envp_cpy[i])
	{
		if (find_variable(cmd->mini->envp_cpy[i], cmd->cmd[1]) == TRUE)
			break ;
		i++;
	}
	if (cmd->mini->envp_cpy[i] != NULL)
		cmd->mini->envp_cpy = realloc_unset(cmd->mini->envp_cpy, i);
}
