/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:16:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/18 18:16:22 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	print_export(char **array)
{
	char	**split;
	int		i;

	i = 0;
	while (array[i])
	{
		if (search_c(array[i], '=') == -1)
			ft_printf("declare -x %s\n", array[i]);
		else if (search_c(array[i], '='))
		{
			split = ft_split(array[i], '=');
			ft_printf("declare -x %s=", split[0]);
			if (split[1])
				ft_printf("\"%s\"", split[1]);
			else
				ft_printf("\"\"");
			ft_printf("\n");
			free_array2d(split);
		}
		i++;
	}
}

int	compare(char **array, char *str)
{
	int	equal;
	int	i;

	equal = search_c(str, '=');
	i = 0;
	if (str[equal - 1] == '+')
		equal = equal - 2;
	while (i < count_args_2d(array) - 1)
	{
		if (!ft_strncmp(array[i], str, equal))
			return (1);
		i++;
	}
	return (0);
}


int	verif_export(t_mini *mini)
{
	int	i;
	int	equal;

	if (!ft_isalpha(mini->cmd[1][0]) || mini->cmd[2])
	{
		ft_printf("export: %s: not a valid identifier\n", mini->cmd[1]);
		return (0);
	}
	i = 1;
	equal = search_c(mini->cmd[1], '=');
	if (equal == -1)
		equal = ft_strlen(mini->cmd[1]);
	while (i < equal)
	{
		if (mini->cmd[1][equal - 1] != '+')
		{
			if (!ft_isalnum(mini->cmd[1][i]))
			{
				ft_printf("export: %s: not a valid identifier\n", mini->cmd[1]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
