/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:07:18 by jduval            #+#    #+#             */
/*   Updated: 2023/04/13 15:52:25 by jduval           ###   ########.fr       */
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
	if (quote_removal(cmdline) < -1)
		return (cmdline);
	cmdline = command_manager(&cmdline);
	return (cmdline);
}

static void	execution_management(t_data *cmdline, t_mini *mini, t_fd *fds)
{
	if (here_doc(cmdline) == -1)
	{
		if (g_status == -130)
			g_status *= -1;
		return ;
	}
	if (is_pipeline(cmdline) == TRUE)
		g_status = pipeline_execution(cmdline, fds, mini);
	else
		g_status = normal_execution(cmdline, mini, fds);
	return ;
}

void	minishell_management(char *line, t_mini *mini, char **envp)
{
	t_data	*cmdline;
	t_fd	fds;

	history(line);
	if (syntactical_parsing(line) == FALSE)
	{
		g_status = 2;
		return ;
	}
	cmdline = data_treatment(line, mini, envp);
	if (cmdline == NULL)
	{
		g_status = 1;
		return ;
	}
	expansion(&cmdline->data.cmd);// A SUPPRIMER
	execution_management(cmdline, mini, &fds);
	display_lst(cmdline, 0);
	free_all_nodes(&cmdline);
	free_array2d(mini->path);
	return ;
}

static void	display_hdoc(char *file, t_hdoc *hdoc);

static void	display_lst(t_data *data, int flag)
{
	t_data	*tmp = data;

	if (flag == 0)
		return ;
	while (tmp != NULL)
	{
		if (tmp->name == REDIRECTION)
		{
			if (tmp->data.rdict.way == HDOC)
				display_hdoc(tmp->data.rdict.file[0], tmp->data.rdict.input);
			else
			{
				ft_printf("-----|REDIRECTION|-----\n");
				ft_printf("-----|INDEX = %i|-----\n", tmp->index);
				ft_printf("|-|file = %s|-|\n", tmp->data.rdict.file[0]);
				ft_printf("|-|WAY = %i|-|\n", tmp->data.rdict.way);
				ft_printf("|-|fd = %i|-|\n", tmp->data.rdict.r_fd);
				ft_printf("|-|fd = %i|-|\n", tmp->data.rdict.w_fd);
			}
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

static void	display_hdoc(char *file, t_hdoc *hdoc)
{
	ft_printf("------|HDOC|------\nfile = %s\n", file);
	while (hdoc != NULL)
	{
		ft_printf("\n|last = %i|\n", hdoc->last);
		ft_printf("%s", hdoc->line);
		hdoc = hdoc->next;
	}
	return ;
}
