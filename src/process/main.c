/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:47:13 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/23 17:58:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/parsing.h"
#include "../../includes/enum.h"

static void	display_lst(t_data *data, int flag);

static void	prompt(t_mini *mini, t_builts *builts, char **envp)
{
	char	*line;
	t_data	*lst;

	builts = NULL;
	envp = NULL;
	while (!mini->exit)
	{
		line = readline("😈 Minishell 😈 ");
		history(line);
		if (syntax_management(line) == FALSE)
		{
			if (line)
				free(line);
			continue ;
		}
		mini->cmd = ft_split(line, ' ');
		lst = make_lst_line(line, mini);
		free(line);
		if (lst == NULL)
		{
			free_array2d(mini->cmd);
			return ;
		}
		display_lst(lst, 1);
		//dollars(mini);
		//is_built(mini);
		free_array2d(mini->cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_builts	*builts;
	t_mini		mini;
	int			exit_s;

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
	free_exit(&mini, builts);
	return (exit_s);
}

static void	display_lst(t_data *data, int flag)
{
	t_data	*tmp = data;

	if (flag == 0)
		return ;
	while (tmp != NULL)
	{
		if (tmp->name == REDIRECTION)
		{
			ft_printf("-----|REDIRECTION|-----\n");
			ft_printf("-----|INDEX = %i|-----\n", tmp->index);
			ft_printf("|-|file = %s|-|\n", tmp->data.rdict.file);
			ft_printf("|-|WAY = %i|-|\n", tmp->data.rdict.way);
			ft_printf("|-|fd = %i|-|\n", tmp->data.rdict.fd);
		}
		else
		{
			ft_printf("-----|COMMAND|-----\n");
			ft_printf("-----|INDEX = %i|-----\n", tmp->index);
			for (int i = 0; tmp->data.cmd.cmd[i]; i++)
				ft_printf("|-|cmd[%i] = %s|-|\n", i, tmp->data.cmd.cmd[i]);
		}
		tmp = tmp->next;
		ft_printf("\n");
	}
}
