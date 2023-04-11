/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/11 09:44:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_pwd(t_cmd *cmd)
{
	char	cwd[PATH_MAX];

	if (count_args_2d(cmd->cmd) > 1)
	{
		printf("To much parameters !\n");
		g_status = 1;
		return ;
	}
	if (!getcwd(cwd, PATH_MAX))
	{
		perror("Error getcwd ");
		g_status = 1;
		return ;
	}
	printf("%s\n", cwd);
	g_status = 0;
}
