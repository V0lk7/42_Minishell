/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/27 17:47:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"

static void	prompt(t_mini *mini, char **envp)
{
	char	*line;

	while (!mini->exit)
	{
		line = readline("😈 Minishell 😈 ");
		minishell_management(line, mini, envp);
		free(line);
		//dollars(mini);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini		mini;
	int			exit_s;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd(2, "Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	init_minishell(&mini, envp);
	prompt(&mini, envp);
	exit_s = mini.exit;
	free_exit(&mini);
	return (exit_s);
}
