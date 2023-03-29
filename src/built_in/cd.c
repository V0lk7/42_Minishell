/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:28:37 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/26 16:45:53 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/built_in.h"

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
		mini->envp_cpy[i] = ft_strjoin("OLDPWD=", mini->old_dir);
	while (mini->envp_cpy[i] && ft_strncmp(mini->envp_cpy[j], "PWD=", 4))
		j++;
	if (j != count_args_2d(mini->envp_cpy))
		mini->envp_cpy[j] = ft_strjoin("PWD=", mini->current_dir);
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

static void	cut_last_directory(t_mini *mini)
{
	char	**dir;
	int		i;
	int		length;

	i = 0;
	dir = ft_split(mini->current_dir, '/');
	length = count_args_2d(dir);
	while (i < length - 1)
	{
		if (i == 0)
			mini->current_dir = ft_strjoin("", "/");
		else
			mini->current_dir = ft_strjoin(mini->current_dir, "/");
		mini->current_dir = ft_strjoin(mini->current_dir, dir[i]);
		i++;
	}
}

void	ft_cd(t_cmd *cmd)
{
	if (!cmd->cmd[1])
	{
		if (find_in(cmd->mini->envp_cpy, "HOME") != -1)
			chdir(find_dir(cmd->mini, "HOME="));
		else
		{
			ft_putstr_fd(2, "cd: HOME not set\n");
			return ;
		}
	}
	else if (!ft_strncmp(cmd->cmd[1], "..", 2))
	{
		cut_last_directory(cmd->mini);
		chdir(cmd->mini->current_dir);
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
	cmd->mini->old_dir = ft_strdup(cmd->mini->current_dir);
	update_pwd(cmd->mini);
}
