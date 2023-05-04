/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/02 14:47:00 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include <readline/readline.h>
#include "../libft/include/libft.h"
#include "../../includes/clear.h"
#include <signal.h>

int	g_status;

static void	prompt(t_mini *mini)
{
	char	*line;

	while (1)
	{
		signal(SIGINT, n_handler);
		signal(SIGQUIT, SIG_IGN);
		line = readline("Minishell : ");
		if (line == NULL)
		{
			ft_printf("exit\n");
			return ;
		}
		minishell_management(line, mini);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini		mini;

	(void)argv;
	g_status = 0;
	if (argc != 1)
	{
		ft_putstr_fd(2, "Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	init_minishell(&mini, envp);
	prompt(&mini);
	free_exit(&mini);
	return (g_status);
}
