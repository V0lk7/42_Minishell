/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:35 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/17 20:13:47 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static char	**sort_export(t_mini *mini)
{
	char	*smallest;
	char	**tmp;
	int		i;
	int		k;

	k = 0;
	tmp = malloc(sizeof(char *) * count_args_2d(mini->envp_cpy));
	while (k < count_args_2d(mini->envp_cpy) - 1)
	{
		i = 0;
		tmp[k] = NULL;
		while (find_in_array2d(tmp, mini->envp_cpy[i]))
			i++;
		smallest = mini->envp_cpy[i];
		i = 0;
		while (i < count_args_2d(mini->envp_cpy))
		{
			if (ft_strcmp(mini->envp_cpy[i], smallest)
				< 0 && !find_in_array2d(tmp, mini->envp_cpy[i]))
				smallest = mini->envp_cpy[i];
			i++;
		}
		tmp[k] = ft_strdup(smallest);
		k++;
	}
	tmp[k] = NULL;
	return (tmp);
}

static char	**add_export(t_mini *mini, char *export)
{
	char	**cpy;
	int		i;
	int		length;

	i = 0;
	length = count_args_2d(mini->envp_cpy);
	cpy = malloc(sizeof(char *) * length );
	while (i < length - 2)
	{
		cpy[i] = ft_strdup(mini->envp_cpy[i]);
		i++;
	}
	cpy[i] = ft_strdup(export);
	cpy[i + 1] = NULL;
	free_array2d(mini->envp_cpy);
	return (cpy);
}

void	ft_export(t_mini *mini)
{
	if (!mini->cmd[1])
		print_export(sort_export(mini));
	else if (mini->cmd[1] && verif_export(mini))
	{
		mini->envp_cpy = add_export(mini, mini->cmd[1]);
		//!cmp_2d(mini->envp_cpy, mini->cmd[1]))
	}
}
