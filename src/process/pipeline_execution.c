/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:50:12 by jduval            #+#    #+#             */
/*   Updated: 2023/03/28 17:58:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/utils.h"
#include "../../includes/process.h"

static void	execution_management(t_data *tmp, t_data *lst, t_fd *fds, t_mini *mini)
{
	int	index;

	index = tmp->index;
	if (pipe_rdir_management(tmp, fds) == 1)
	{
		free_all(lst, mini);
		exit (1);//set la global en erreur je suppose
	}
	tmp = redirection_management(tmp, fds, tmp->index);
	if (tmp && tmp->index == index && tmp->name == COMMAND)
	{
		if (tmp->data.cmd.valid == 0)
		{
			if (tmp->data.cmd.id >= 0)
				is_built(&tmp->data.cmd);
			else
			{
				if (tmp->data.cmd.valid < 0)
					command_not_found(tmp->data.cmd.cmd[0]);
				else
				{
					execve(tmp->data.cmd.cmd[0], tmp->data.cmd.cmd, mini->envp_cpy);
					perror(NULL);
					//set variable global a 127 jcrois
				}
			}
		}
	}
	free_all(lst, mini);
	exit(0); //global plus tard
}

int	pipeline_execution(t_data *lst, t_fd *fds, t_mini *mini)
{
	t_data	*tmp;
	pid_t	pid;
	int		last;

	last = find_last_sequence(lst);
	tmp = lst;
	while (tmp)
	{
		if (tmp->index < last)
		{
			pipe(fds->fds);
			fds->write = fds->fds[1];
		}
		pid = fork();
		if (pid == 0)
			execution_management(tmp, lst, fds, mini);
		tmp = next_sequence(tmp);
		fds->read = fds->fds[0];
		close(fds->fds[1]);
	}
	close(fds->read);
	waitpid(pid, &mini->exit, 0);
	while (waitpid(-1, NULL, 0) > -1)
		continue ;
	return (mini->exit);
}
