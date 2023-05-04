/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:10 by jduval            #+#    #+#             */
/*   Updated: 2023/05/02 15:27:56 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"
#include <linux/limits.h>

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

static int	error_unset(char *cmd)
{
	if (cmd[0] == '-')
	{
		ft_printf("unset: %s: invalid option\n", cmd);
		g_status = 2;
		return (0);
	}
	if (!ft_isalpha(cmd[0]))
	{
		ft_printf("unset: '%s': not a valid identifier\n", cmd);
		g_status = 1;
		return (0);
	}
	return (1);
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
	int		j;

	j = 1;
	g_status = 0;
	if (!cmd->cmd[1])
		return ;
	while (cmd->cmd[j])
	{
		i = 0;
		if (error_unset(cmd->cmd[j]) == 1)
		{
			while (cmd->mini->envp_cpy[i] && find_variable
				(cmd->mini->envp_cpy[i], cmd->cmd[j]) == FALSE)
				i++;
			if (cmd->mini->envp_cpy[i] != NULL)
				cmd->mini->envp_cpy = realloc_unset(cmd->mini->envp_cpy, i);
		}
		j++;
	}
}
