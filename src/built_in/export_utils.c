/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:16:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/17 20:11:47 by kramjatt         ###   ########.fr       */
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
		split = ft_split(array[i], '=');
		ft_printf("declare -x %s=", split[0]);
		ft_printf("\"%s\"", split[1]);
		ft_printf("\n");
		i++;
		free_array2d(split);
	}
}

int	cmp_2d(char **array, char *str)
{
	int	i;

	i = 0;
	while (i < count_args_2d(array) - 1)
	{
		if (!ft_strncmp(array[i], str, ft_strlen(str)))
			return (1);
		i++;
	}
	return (0);
}

int	verif_export(t_mini *mini)
{
	int	i;

	i = 0;
	if (ft_isdigit(mini->cmd[1][0]) || mini->cmd[2])
	{
		ft_printf("export: %s: not a valid identifier\n", mini->cmd[1]);
		return (0);
	}
	while (mini->cmd[1][i])
	{
		if (!ft_isalnum(mini->cmd[1][i]))
		{
			ft_printf("export: %s: not a valid identifier\n", mini->cmd[1]);
			return (0);
		}
		i++;
	}
	return (1);
}
