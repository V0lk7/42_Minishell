/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by jduval            #+#    #+#             */
/*   Updated: 2023/03/10 15:45:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_env(t_mini *mini)
{
	int		i;
	int		length;

	i = 0;
	if (!mini->envp_cpy)
		return ;
	length = count_args_2d(mini->envp_cpy);
	while (i < length)
	{
		printf("%s\n", mini->envp_cpy[i]);
		i++;
	}
}
