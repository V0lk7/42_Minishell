/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:50:12 by jduval            #+#    #+#             */
/*   Updated: 2023/03/30 13:49:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/utils.h"
#include "../../includes/process.h"
#include <sys/types.h>
#include <sys/wait.h>

static int	exec_utils(t_data *tmp, t_mini *mini)
{
	int	flag;

	flag = 1;
	if (tmp->data.cmd.valid < 0)
		flag = errors_command(&tmp->data.cmd);
	else
	{
		execve(tmp->data.cmd.cmd[0], tmp->data.cmd.cmd, mini->envp_cpy);
		perror("😈 Minishell 😈 ");
	}
	return (flag);
}

void	execution_part(t_data *tmp, t_data *lst, t_fd *fds, t_mini *mini)
{
	int	index;
	int	flag;

	flag = 0;
	index = tmp->index;
	if (pipe_rdir_management(tmp, fds) == 1)
	{
		perror("😈 Minishell 😈 ");
		free_all(lst, mini);
		exit (1);
	}
	tmp = redirection_management(tmp, fds, tmp->index);
	if (tmp && tmp->index == index && tmp->name == COMMAND)
	{
		if (tmp->data.cmd.id >= 0)
			is_built(&tmp->data.cmd);
		else
			flag = exec_utils(tmp, mini);
	}
	free_all(lst, mini);
	exit(flag);
}

void	close_fd_pipe(t_data *tmp, t_fd *fds, int last)
{
	if (tmp && tmp->index > 0)
		close (fds->read);
	if (tmp && tmp->index < last)
		close(fds->fds[1]);
	return ;
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
	waitpid(pid, &last, 0);
	while (waitpid(-1, NULL, 0) > -1)
		continue ;
	return (WEXITSTATUS(last));
}
