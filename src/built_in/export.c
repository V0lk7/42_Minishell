/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:35 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/03 16:51:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"

char	**add_export(t_mini *mini, char *exported)
{
	char	**cpy;
	int		i;
	int		length;

	i = -1;
	length = count_args_2d(mini->envp_cpy);
	cpy = malloc(sizeof(char *) * (length + 2));
	while (++i < length)
		cpy[i] = ft_strdup(mini->envp_cpy[i]);
	cpy[i] = ft_strdup(exported);
	cpy[i + 1] = NULL;
	free_array2d(mini->envp_cpy);
	return (cpy);
}

static void	add_export_plus(t_mini *mini, char *export)
{
	char	*without_plus;
	int		i;
	int		j;
	int		equal;
	int		length;

	i = 0;
	j = 0;
	length = find_in_eq(mini->envp_cpy, export);
	if (length == -1)
		length = count_args_2d(mini->envp_cpy) - 1;
	equal = search_c(export, '=');
	without_plus = malloc(sizeof(char) * (ft_strlen(export) + 1));
	while (i < (int)ft_strlen(export))
	{
		if (i != equal - 1)
		{
			without_plus[j] = export[i];
			j++;
		}
		i++;
	}
	without_plus[j] = '\0';
	free(mini->envp_cpy[length]);
	mini->envp_cpy[length] = without_plus;
}

static void	join_export(t_mini *mini, char *export)
{
	char	*cpy;
	int		equal;
	int		i;
	int		j;

	equal = search_c(export, '=') + 1;
	i = -1;
	while (++i < count_args_2d(mini->envp_cpy) - 1)
		if (!ft_strncmp(mini->envp_cpy[i], export, equal - 2))
			break ;
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
		cpy = ft_strjoin_free_s2("=", cpy);
	mini->envp_cpy[i] = ft_strjoin_free(mini->envp_cpy[i], cpy);
	free(cpy);
}

static void	ifs_export(t_cmd *cmd, int equal, int i)
{
	if (equal != -1)
	{
		if (find_in_eq(cmd->mini->envp_cpy, cmd->cmd[i]) == -1
			&& cmd->cmd[i][equal - 1] != '+')
			cmd->mini->envp_cpy = add_export(cmd->mini, cmd->cmd[i]);
		else if (find_in_eq(cmd->mini->envp_cpy, cmd->cmd[i]) != -1
			&& cmd->cmd[i][equal - 1] != '+')
			crush_export(cmd->mini, cmd->cmd[i]);
		else if (find_in_eq(cmd->mini->envp_cpy, cmd->cmd[i]) == -1
			&& cmd->cmd[i][equal - 2] == '+')
			join_export(cmd->mini, cmd->cmd[i]);
		else if (find_in_eq(cmd->mini->envp_cpy, cmd->cmd[i]) == -1
			&& cmd->cmd[i][equal - 1] == '+')
			add_export_plus(cmd->mini, cmd->cmd[i]);
	}
	else
		if (find_in(cmd->mini->envp_cpy, cmd->cmd[i]) == -1)
			cmd->mini->envp_cpy = add_export(cmd->mini, cmd->cmd[i]);
}

void	ft_export(t_cmd *cmd)
{
	int		i;
	int		equal;
	char	**sorted;

	i = 1;
	g_status = 0;
	if (!cmd->cmd[1])
	{
		sorted = sort_export(cmd->mini);
		print_export(sorted);
		free_array2d(sorted);
	}
	else if (cmd->cmd[1])
	{
		while (cmd->cmd[i])
		{
			if (verif_export(cmd->cmd[i]) == 1)
			{
				equal = search_c(cmd->cmd[i], '=');
				ifs_export(cmd, equal, i);
			}
			i++;
		}
	}
}
