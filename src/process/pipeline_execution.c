/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:50:12 by jduval            #+#    #+#             */
/*   Updated: 2023/05/02 13:28:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/clear.h"
#include "../../includes/process.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

int	exec_utils(t_data *tmp, t_mini *mini)
{
	int	status;

	if (tmp->data.cmd.valid == 2)
		return (0);
	if (tmp->data.cmd.valid < 0)
		status = errors_command(&tmp->data.cmd);
	else
	{
		execve(tmp->data.cmd.cmd[0], tmp->data.cmd.cmd, mini->envp_cpy);
		errors(tmp->data.cmd.cmd[0]);
		status = 126;
	}
	return (status);
}

void	execution_part(t_data *tmp, t_data *lst, t_fd *fds, t_mini *mini)
{
	int	index;

	index = tmp->index;
	signal(SIGQUIT, SIG_DFL);
	if (pipe_rdir_management(tmp, fds) == 1)
	{
		free_all(lst, mini);
		exit (errno);
	}
	tmp = redirection_management(tmp, fds, tmp->index);
	close_here_doc(lst);
	if (tmp && tmp->index == index && tmp->name == COMMAND)
		chose_builtin_or_exec(tmp, lst, mini);
	free_all(lst, mini);
	exit(g_status);
}

void	close_fd_pipe(t_data *tmp, t_fd *fds, int last)
{
	if (tmp && tmp->index > 0 && tmp->index < last)
		close (fds->read);
	if (tmp && tmp->index < last)
		close(fds->fds[1]);
	return ;
}

static int	utils_end_pipeline(pid_t pid, int fd)
{
	int	status;

	signal(SIGQUIT, f_handler);
	signal(SIGINT, f_handler);
	status = wait_function(pid);
	close(fd);
	wait_function(-1);
	if (status == 2 && g_status == 130)
		status = 130;
	return (status);
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
			execution_part(tmp, lst, fds, mini);
		close_fd_pipe(tmp, fds, last);
		tmp = next_sequence(tmp);
		fds->read = fds->fds[0];
	}
	last = utils_end_pipeline(pid, fds->read);
	if (last == 130 || last == 131)
		return (last);
	return (last);
}
