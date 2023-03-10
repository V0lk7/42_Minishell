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

#include "../../includes/minishell.h"

void	ft_env(t_minis *minis)
{
	int		i;
	int		length;

	i = 0;
	if (!minis->envp_cpy)
		return ;
	length = count_args_2d(minis->envp_cpy);
	while (i < length)
	{
		printf("%s\n", minis->envp_cpy[i]);
		i++;
	}
}
