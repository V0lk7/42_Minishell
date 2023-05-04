/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_minishell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:07:18 by jduval            #+#    #+#             */
/*   Updated: 2023/05/03 09:33:54 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/parsing.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"
#include "../../includes/utils.h"

static t_data	*data_treatment(char *line, t_mini *mini)
{
	t_data	*cmdline;

	mini->path = make_array_path(mini->envp_cpy);
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
	expansion_management(cmdline, mini);
	cmdline = command_manager(&cmdline);
	return (cmdline);
}

static void	execution_management(t_data *cmdline, t_mini *mini, t_fd *fds)
{
	if (here_doc(cmdline, mini) == 1)
	{
		if (g_status == -130)
			g_status *= -1;
		else
			g_status = 1;
		return ;
	}
	if (is_pipeline(cmdline) == TRUE)
		g_status = pipeline_execution(cmdline, fds, mini);
	else
		g_status = normal_execution(cmdline, mini, fds);
	return ;
}

void	minishell_management(char *line, t_mini *mini)
{
	t_data	*cmdline;
	t_fd	fds;

	if (line[0] == '\0')
		return ;
	history(line);
	if (empty_line(line) == TRUE)
		return ;
	if (syntactical_parsing(line) == FALSE)
	{
		g_status = 2;
		return ;
	}
	cmdline = data_treatment(line, mini);
	if (cmdline == NULL)
	{
		g_status = 1;
		return ;
	}
	execution_management(cmdline, mini, &fds);
	free_all_nodes(&cmdline);
	free_array2d(mini->path);
	return ;
}
