/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:30:42 by jduval            #+#    #+#             */
/*   Updated: 2023/04/04 13:33:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/utils.h"
#include "../../includes/built_in.h"
#include "../../includes/enum.h"
#include <errno.h>

static int	cmd_exec_part(t_data *tmp, t_mini *mini)
{
	int	status;

	
	if (tmp->data.cmd.valid < 0)
		status = errors_command(&tmp->data.cmd);
	else
	{
		execve(tmp->data.cmd.cmd[0], tmp->data.cmd.cmd, mini->envp_cpy);
		perror(NULL);
		status = errno;
		//g_status = errno;
	}
	return (status);
}

static int	command_execution(t_data *lst, t_fd *fds, t_mini *mini)
{
	pid_t	pid;
	t_data	*tmp;
	int		status;

	tmp = lst;
	status = 0;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, f_handler);
		tmp = redirection_management(tmp, fds, tmp->index);
		if (tmp->name == COMMAND)
			status = cmd_exec_part(tmp, mini);
		free_all(lst, mini);
		exit(status);
	}
	signal(SIGQUIT, f_handler);
	signal(SIGINT, f_handler);
	waitpid(pid, &status, 0);
	if (g_status > 129)
		return (g_status);
	else
		return (WEXITSTATUS(status));
}

static int	builtin_execution(t_data *lst, t_fd *fds, int id)
{
	if (id != 3)
	{
		fds->std_in = dup(STDIN_FILENO);
		fds->std_out = dup(STDOUT_FILENO);
	}
	lst = redirection_management(lst, fds, lst->index);
	if (lst && lst->name == COMMAND)
		is_built(&lst->data.cmd);
	if (id == 3)
		return (g_status);
	if (dup2(fds->std_in, STDIN_FILENO) == -1)
		perror(NULL);
	if (dup2(fds->std_out, STDOUT_FILENO) == -1)
		perror(NULL);
	close(fds->std_in);
	close(fds->std_out);
	return (g_status);
}

int	normal_execution(t_data *lst, t_mini *mini, t_fd *fds)
{
	int		type;
	int		status;

	type = type_of_cmd(lst);
	if (type >= 0 || type == -2)
		status = builtin_execution(lst, fds, type);
	else
		status = command_execution(lst, fds, mini);
	return (status);
}
