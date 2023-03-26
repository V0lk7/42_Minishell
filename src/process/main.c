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

static void	display_lst(t_data *data, int flag);

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
		display_lst(lst, 1);
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
			ft_printf("|-|valid = %i|-|\n", tmp->data.cmd.valid);
			ft_printf("|-|id = %i|-|\n", tmp->data.cmd.id);
			for (int i = 0; tmp->data.cmd.cmd[i]; i++)
				ft_printf("|-|cmd[%i] = %s|-|\n", i, tmp->data.cmd.cmd[i]);
		}
		tmp = tmp->next;
		ft_printf("\n");
	}
}
