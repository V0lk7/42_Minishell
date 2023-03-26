/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:38 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 15:58:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

void	ft_pwd(t_cmd *cmd)
{
	char	cwd[PATH_MAX];

	(void)cmd;
	if (!getcwd(cwd, PATH_MAX))
	{
		perror("Error getcwd ");
		return ;
	}
	printf("%s\n", cwd);
}
