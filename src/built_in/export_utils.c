/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:16:38 by kramjatt          #+#    #+#             */
/*   Updated: 2023/04/25 17:40:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"

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

char	**sort_export(t_mini *mini)
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
		i = -1;
		while (++i < count_args_2d(mini->envp_cpy))
			if (ft_strcmp(mini->envp_cpy[i], smallest)
				< 0 && !find_in_array2d(tmp, mini->envp_cpy[i]))
				smallest = mini->envp_cpy[i];
		tmp[k] = ft_strdup(smallest);
		k++;
	}
	tmp[k] = NULL;
	return (tmp);
}

static int	error_export(char *cmd)
{
	if (cmd[0] == '-')
	{
		ft_printf("export: %s : option non valable\n", cmd);
		g_status = 2;
		return (0);
	}
	if (!ft_isalpha(cmd[0]))
	{
		ft_printf("export: %s: not a valid identifier\n", cmd);
		g_status = 1;
		return (0);
	}
	return (1);
}

int	verif_export(char *cmd)
{
	int	i;
	int	equal;

	i = 1;
	if (!error_export(cmd))
		return (0);
	equal = search_c(cmd, '=');
	if (equal == -1)
		equal = ft_strlen(cmd);
	while (i < equal)
	{
		if (cmd[equal - 1] != '+')
		{
			if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			{
				ft_printf("export: %s: not a valid identifier\n", cmd);
				g_status = 1;
				return (0);
			}
		}
		i++;
	}
	return (1);
}

void	crush_export(t_mini *mini, char *exported)
{
	int	find;

	find = find_in_eq(mini->envp_cpy, exported);
	mini->envp_cpy[find] = ft_strdup(exported);
	return ;
}
