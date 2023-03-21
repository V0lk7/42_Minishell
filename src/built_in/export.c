/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:35 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/18 19:32:44 by kramjatt         ###   ########.fr       */
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

/*static int	check_char(char *str, char *export)
{
	int	equal;

	equal = search_c(str, '=');
	if (equal == -1 && !ft_strncmp(str, export, ft_strlen(export)))
		return (-1);
	if (equal == -1 && ft_strncmp(str, export, ft_strlen(export)))
		return (1);
	if (equal != -1  && !ft_strncmp(str, export, equal - 1))
		return (1);
	else
		return (0);

}*/

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

void	ft_export(t_mini *mini)
{
	int	equal;

	if (!mini->cmd[1])
		print_export(sort_export(mini));
	else if (mini->cmd[1] && verif_export(mini))
	{
		equal = search_c(mini->cmd[1], '=');
		if (equal == -1)
			mini->envp_cpy = add_export(mini, mini->cmd[1]);
		else if (equal != -1 && mini->cmd[1][equal - 1] != '+')
			mini->envp_cpy = add_export(mini, mini->cmd[1]);
		else if (compare(mini->envp_cpy, mini->cmd[1])
			&& mini->cmd[1][equal - 1] == '+')
			join_export(mini, mini->cmd[1]);
	}
}
