/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:35 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/26 16:21:56 by jduval           ###   ########.fr       */
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
	tmp = malloc(sizeof(char *) * (count_args_2d(mini->envp_cpy) + 1));
	while (k < count_args_2d(mini->envp_cpy))
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

static void	crush_export(t_mini *mini, char *export)
{
	int	find;

	find = find_in_eq(mini->envp_cpy, export);
	mini->envp_cpy[find] = ft_strdup(export);
	return ;
}

static char	**add_export(t_mini *mini, char *export)
{
	char	**cpy;
	int		i;
	int		length;

	i = 0;
	length = count_args_2d(mini->envp_cpy);
	cpy = malloc(sizeof(char *) * (length + 2));
	while (i < length)
	{
		cpy[i] = ft_strdup(mini->envp_cpy[i]);
		i++;
	}
	cpy[i] = ft_strdup(export);
	cpy[i + 1] = NULL;
	return (cpy);
}

static void	join_export(t_mini *mini, char *export)
{
	char	*cpy;
	int		equal;
	int		i;
	int		j;

	equal = search_c(export, '=') + 1;
	i = 0;
	while (i < count_args_2d(mini->envp_cpy) - 1)
	{
		if (!ft_strncmp(mini->envp_cpy[i], export, equal - 2))
			break ;
		i++;
	}
	cpy = malloc(sizeof(char) * (ft_strlen(export) - equal + 1));
	j = 0;
	while (equal < (int)ft_strlen(export))
	{
		cpy[j] = export[equal];
		equal++;
		j++;
	}
	cpy[j] = '\0';
	if (mini->envp_cpy[i][ft_strlen(mini->envp_cpy[i])] == '\0'
		&& search_c(mini->envp_cpy[i], '=') == -1)
		cpy = ft_strjoin("=", cpy);
	mini->envp_cpy[i] = ft_strjoin(mini->envp_cpy[i], cpy);
}

void	ft_export(t_cmd *cmd)
{
	int	equal;
	int	i;

	i = 1;
	if (!cmd->cmd[1])
		print_export(sort_export(cmd->mini));
	else if (cmd->cmd[1])
	{
		while (cmd->cmd[i] && verif_export(cmd->cmd[i]))
		{
			equal = search_c(cmd->cmd[i], '=');
			if (equal != -1)
			{
				if (find_in_eq(cmd->mini->envp_cpy, cmd->cmd[i]) == -1 && cmd->cmd[i][equal - 1] != '+')
					cmd->mini->envp_cpy = add_export(cmd->mini, cmd->cmd[i]);
				else if (find_in_eq(cmd->mini->envp_cpy, cmd->cmd[i]) != -1 && cmd->cmd[i][equal - 1] != '+')
					crush_export(cmd->mini, cmd->cmd[i]);
				else if (compare(cmd->mini->envp_cpy, cmd->cmd[i]) && cmd->cmd[i][equal - 1] == '+')
					join_export(cmd->mini, cmd->cmd[i]);
			}
			else
				if (find_in(cmd->mini->envp_cpy, cmd->cmd[i]) == -1)
					cmd->mini->envp_cpy = add_export(cmd->mini, cmd->cmd[i]);
			i++;
		}
	}
}
