/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/26 18:47:38 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"

static void	prompt(t_mini *mini, char **envp)
{
	char	*line;
	t_data	*lst;

	while (!mini->exit)
	{
		line = readline("😈 Minishell 😈 ");
		history(line);
		if (syntax_management(line) == FALSE)
		{
			free(line);
			continue ;
		}
		mini->path = make_array_path(envp); 
		lst = make_lst_line(line, mini);
		free(line);
		if (lst == NULL)
		{
			free_array2d(mini->path);
			return ;
		}
		lst = command_manager(&lst);
		if (lst == NULL)
		{
			free_array2d(mini->path);
			return ;
		}
		//dollars(mini);
		is_built(&lst->data.cmd);
		free_all_nodes(&lst);
		free_array2d(mini->path);
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
