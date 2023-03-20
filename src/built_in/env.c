/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by jduval            #+#    #+#             */
/*   Updated: 2023/03/18 17:14:48 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_env(t_mini *mini)
{
	int		i;
	int		j;
	int		null;
	int		length;

	i = 0;
	if (!mini->envp_cpy)
		return ;
	length = count_args_2d(mini->envp_cpy);
	while (i < length)
	{
		j = 0;
		null = 0;
		while (mini->envp_cpy[i][j])
		{
			if (mini->envp_cpy[i][j] == '=')
				null++;
			j++;
		}
		if (null)
			printf("%s\n", mini->envp_cpy[i]);
		i++;
	}
}
