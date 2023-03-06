/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 20:29:38 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	prompt(t_minis *minis, t_builts *builts, char **envp)
{
	char	*line;

	while (1)
	{
		line = readline("😈 Minishell 😈 ");
		history(line);
		minis->cmd = ft_split(line, 32);
		is_built(minis);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_builts	*builts;
	t_minis		*minis;

	(void)argc;
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd(2, "Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	builts = malloc(sizeof(t_builts) * 8);
	minis = malloc(sizeof(t_minis));
	init_builts(builts);
	init_minishell(minis, builts, envp);
	prompt(minis, builts, envp);
	return (0);
}
