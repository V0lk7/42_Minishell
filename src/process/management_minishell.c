/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:07:18 by jduval            #+#    #+#             */
/*   Updated: 2023/03/28 17:48:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"
#include "../../includes/utils.h"

static void	display_lst(t_data *data, int flag);

static t_data	*data_treatment(char *line, t_mini *mini, char **envp)
{
	t_data	*cmdline;

	mini->path = make_array_path(envp);
	if (mini->path == NULL)
		return (NULL);
	cmdline = make_lst_line(line, mini);
	if (cmdline == NULL)
	{
		free_array2d(mini->path);
		return (NULL);
	}
	//position of variable expansion and quote removal
	cmdline = command_manager(&cmdline);
	return (cmdline);
}

static void	execution_management(t_data *cmdline, t_mini *mini, t_fd *fds)
{
	if (is_pipeline(cmdline) == TRUE)
		pipeline_execution(cmdline, fds, mini);
	else
		normal_execution(cmdline, mini, fds);
	return ;
}

void	minishell_management(char *line, t_mini *mini, char **envp)
{
	t_data	*cmdline;
	t_fd	fds;

	history(line);
	if (syntactical_parsing(line) == FALSE)
		return ;
	cmdline = data_treatment(line, mini, envp);
	if (cmdline == NULL)
		return ;
	execution_management(cmdline, mini, &fds);
	display_lst(cmdline, 0);
	free_all_nodes(&cmdline);
	free_array2d(mini->path);
	return ;
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
