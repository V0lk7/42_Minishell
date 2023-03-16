/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:28:37 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/16 16:38:41 by kramjatt         ###   ########.fr       */
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
	while (ft_strncmp(mini->envp_cpy[i], "OLDPWD=", 7))
		i++;
	mini->envp_cpy[i] = ft_strjoin("OLDPWD=", mini->old_dir);
	while (ft_strncmp(mini->envp_cpy[j], "PWD=", 4))
		j++;
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

void	ft_cd(t_mini *mini)
{
	mini->old_dir = ft_strdup(mini->current_dir);
	if (!mini->cmd[1])
		chdir(find_dir(mini, "HOME="));
	else if (!ft_strncmp(mini->cmd[1], "..", 2))
	{
		cut_last_directory(mini);
		chdir(mini->current_dir);
	}
	else if (mini->cmd[1])
	{
		if (chdir(mini->cmd[1]) == -1)
		{
			ft_printf("cd : %s ", mini->cmd[1]);
			perror(0);
		}
	}
	update_pwd(mini);
}
