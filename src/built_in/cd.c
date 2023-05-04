/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:28:37 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/03 16:49:22 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"
#include "../libft/include/libft.h"
#include "../../includes/enum.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	update_pwd(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	free(mini->current_dir);
	mini->current_dir = malloc(sizeof(char) * PATH_MAX);
	if (!getcwd(mini->current_dir, PATH_MAX))
		perror(0);
	while (mini->envp_cpy[i] && ft_strncmp(mini->envp_cpy[i], "OLDPWD=", 7))
		i++;
	if (i != count_args_2d(mini->envp_cpy))
	{
		free(mini->envp_cpy[i]);
		mini->envp_cpy[i] = ft_strjoin("OLDPWD=", mini->old_dir);
	}
	while (mini->envp_cpy[j] && ft_strncmp(mini->envp_cpy[j], "PWD=", 4))
		j++;
	if (j != count_args_2d(mini->envp_cpy))
	{
		free(mini->envp_cpy[j]);
		mini->envp_cpy[j] = ft_strjoin("PWD=", mini->current_dir);
	}
}

static char	*find_dir(t_mini *mini, char *str)
{
	char	*pwd;
	int		i;

	i = 0;
	while (ft_strncmp(mini->envp_cpy[i], str, ft_strlen(str)))
		i++;
	pwd = cut(mini->envp_cpy[i], '=');
	return (pwd);
}

static void	cd_home(t_cmd *cmd)
{
	char	*str;

	if (find_in(cmd->mini->envp_cpy, "HOME") != -1)
	{
		str = find_dir(cmd->mini, "HOME=");
		chdir(str);
		free(str);
	}
	else
	{
		ft_putstr_fd(2, "cd: HOME not set\n");
		g_status = 1;
		return ;
	}
}

void	ft_cd(t_cmd *cmd)
{
	g_status = 0;
	if (!cmd->cmd[1])
		cd_home(cmd);
	else if (count_args_2d(cmd->cmd) > 2)
	{
		ft_putstr_fd(2, "Minishell: cd: too many arguments\n");
		g_status = 1;
	}
	else if (cmd->cmd[1])
	{
		if (chdir(cmd->cmd[1]) == -1)
		{
			ft_printf("cd : %s ", cmd->cmd[1]);
			perror(0);
			g_status = 1;
		}
	}
	if (cmd->mini->old_dir)
		free(cmd->mini->old_dir);
	cmd->mini->old_dir = ft_strdup(cmd->mini->current_dir);
	update_pwd(cmd->mini);
}
