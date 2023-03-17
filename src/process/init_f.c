/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:46:35 by jduval            #+#    #+#             */
/*   Updated: 2023/03/17 22:12:53 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include <linux/limits.h>
#include <unistd.h>

void	init_builts(t_builts *builts)
{
	builts[0].str = malloc(sizeof(char) * ft_strlen("cd") + 1);
	builts[1].str = malloc(sizeof(char) * ft_strlen("echo") + 1);
	builts[2].str = malloc(sizeof(char) * ft_strlen("env") + 1);
	builts[3].str = malloc(sizeof(char) * ft_strlen("exit") + 1);
	builts[4].str = malloc(sizeof(char) * ft_strlen("export") + 1);
	builts[5].str = malloc(sizeof(char) * ft_strlen("pwd") + 1);
	builts[6].str = malloc(sizeof(char) * ft_strlen("unset") + 1);
	builts[0].str = "cd";
	builts[1].str = "echo";
	builts[2].str = "env";
	builts[3].str = "exit";
	builts[4].str = "export";
	builts[5].str = "pwd";
	builts[6].str = "unset";
}

void	init_minishell(t_mini *mini, t_builts *builts, char **envp)
{
	mini->b_ptr = builts;
	mini->current_dir = malloc(sizeof(char) * PATH_MAX);
	getcwd(mini->current_dir, PATH_MAX);
	mini->envp_cpy = cpy_array2d(envp);
	mini->exit = 0;
}
