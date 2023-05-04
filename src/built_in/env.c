/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by jduval            #+#    #+#             */
/*   Updated: 2023/05/03 17:04:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"

static void	invalid_option(char *str)
{
	ft_putstr_fd(2, "env: invalid option -- '");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, "'\n");
}

static void	no_file(char *str)
{
	ft_putstr_fd(2, "env: '");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, "' No such file or directory\n");
}

static void	loop_env(t_cmd *cmd)
{
	int		i;
	int		j;
	int		null;
	int		length;

	i = 0;
	length = count_args_2d(cmd->mini->envp_cpy);
	while (i < length)
	{
		j = 0;
		null = 0;
		while (cmd->mini->envp_cpy[i][j])
		{
			if (cmd->mini->envp_cpy[i][j] == '=')
				null++;
			j++;
		}
		if (null)
			ft_printf("%s\n", cmd->mini->envp_cpy[i]);
		i++;
	}
}

void	ft_env(t_cmd *cmd)
{
	g_status = 0;
	if (!cmd->mini->envp_cpy)
		return ;
	if (cmd->cmd[1] && cmd->cmd[1][0] == '-')
	{
		invalid_option(cmd->cmd[1]);
		g_status = 125;
	}
	else if (cmd->cmd[1])
	{
		no_file(cmd->cmd[1]);
		g_status = 127;
	}
	else
		loop_env(cmd);
}
