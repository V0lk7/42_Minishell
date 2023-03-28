/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:30:42 by jduval            #+#    #+#             */
/*   Updated: 2023/03/28 17:51:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/utils.h"
#include "../../includes/built_in.h"
#include "../../includes/enum.h"

static void	builtin_execution(t_data *lst, t_fd *fds)
{
	fds->std_in = dup(STDIN_FILENO);
	fds->std_out = dup(STDOUT_FILENO);
	lst = redirection_management(lst, fds, lst->index);
	if (lst && lst->name == COMMAND)
		is_built(&lst->data.cmd);
	if (dup2(fds->std_in, STDIN_FILENO) == -1)
		perror(NULL);
	if (dup2(fds->std_out, STDOUT_FILENO) == -1)
		perror(NULL);
	close(fds->std_in);
	close(fds->std_out);
	return ;
}

static int	command_execution(t_data *lst, t_fd *fds, t_mini *mini)
{
	pid_t	pid;
	t_data	*tmp;
	int		wstatus;

	tmp = lst;
	pid = fork();
	if (pid == 0)
	{
		tmp = redirection_management(tmp, fds, tmp->index);
		if (tmp->name == COMMAND)
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
		free_all(lst, mini);
		exit(0);//global plus tard
	}
	waitpid(pid, &wstatus, 0);
	return (wstatus);//gobal
}

void	normal_execution(t_data *lst, t_mini *mini, t_fd *fds)
{
	int		type;

	//here_doc(lst);
	type = type_of_cmd(lst);
	if (type >= 0 || type == -2)
		builtin_execution(lst, fds);
	else if (type == -1)
		command_execution(lst, fds, mini);
	return ;
}
