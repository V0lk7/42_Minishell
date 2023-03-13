/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/13 17:06:25 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"

static int	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

static void	prompt(t_mini *mini, t_builts *builts, char **envp)
{
	char	*line;

	while (!mini->exit)
	{
		line = readline("😈 Minishell 😈 ");
		history(line);
		if (line && !only_spaces(line))
		{
			mini->cmd = ft_split(line, 32);
			is_built(mini);
			free(line);
			free_array2d(mini->cmd);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_builts	*builts;
	t_mini		mini;
	int			exit_s;

	(void)argc;
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd(2, "Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	builts = malloc(sizeof(t_builts) * 7);
	init_builts(builts);
	init_minishell(&mini, builts, envp);
	prompt(&mini, builts, envp);
	exit_s = mini.exit;
	//free_exit(&mini, builts);
	return (exit_s);
}
