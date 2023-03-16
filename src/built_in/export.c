/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:42:35 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/16 20:00:25 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

static int	find(char **array, char *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!ft_strcmp(array[i], str))
			return (1);
		i++;
	}
	return (0);
}

static void	print_export(t_mini *mini)
{
	char	*onverra;
	char	**tmp;
	int		i;
	int		k;

	k = 0;
	tmp = malloc(sizeof(char *) * count_args_2d(mini->envp_cpy));
	while (k < count_args_2d(mini->envp_cpy))
	{
		i = 0;
		while (find(tmp, mini->envp_cpy[i]))
			i++;
		onverra = mini->envp_cpy[i];
		i = 0;
		while (mini->envp_cpy[i])
		{
			if (ft_strcmp(mini->envp_cpy[i], onverra) < 0 && !find(tmp, mini->envp_cpy[i]))
				onverra = mini->envp_cpy[i];
			i++;
		}
		tmp[k] = ft_strdup(onverra);
		k++;
	}
	k = 0;
	while (k < count_args_2d(mini->envp_cpy))
	{
		ft_printf("%s\n", tmp[k]);
		k++;
	}
}

void	ft_export(t_mini *mini)
{
	if (!mini->cmd[1])
		print_export(mini);
	else
		ft_printf("En cours d'implementation");
}
