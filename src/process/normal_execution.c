/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:30:42 by jduval            #+#    #+#             */
/*   Updated: 2023/03/27 17:31:48 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/built_in.h"
#include "../../includes/enum.h"

//->here doc
//->verif si built in, si oui -> redirect in parent
//->si non redirect dans le fork.
//->redirection
//->execution builtin ou execve.
//->sortie

static void	builtin_execution(t_data *lst, t_fd *fds)
{
	t_data	*tmp;

	tmp = lst;
	fds->std_in = dup(STDIN_FILENO);
	fds->std_out = dup(STDOUT_FILENO);
	while (tmp && tmp->name == REDIRECTION)
	{
		if (tmp->data.rdict.way == IN)
		{
			fds->read = open(tmp->data.rdict.file, O_RDONLY);
			if (fds->read == -1)
			{
				perror(NULL);
				break ;
			}
			if (dup2(fds->read, STDIN_FILENO) == -1)
			{
				perror(NULL);
				break ;
			}
			close(fds->read);
		}
		else if (tmp->data.rdict.way == HDOC)
		{
			fds->read = tmp->data.rdict.fd;
			if (fds->read == -1)
				break ;
			if (dup2(fds->read, STDIN_FILENO) == -1)
			{
				perror(NULL);
				break ;
			}
			close(fds->read);
		}
		else if (tmp->data.rdict.way == OUT)
		{
			fds->write = open(tmp->data.rdict.file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			if (fds->write == -1)
			{
				perror(NULL);
				break ;
			}
			if (dup2(fds->write, STDOUT_FILENO) == -1)
			{
				perror(NULL);
				break ;
			}
			close(fds->write);
		}
		else
		{
			fds->write = open(tmp->data.rdict.file, O_CREAT | O_APPEND | O_WRONLY, 0644);
			if (fds->write == -1)
			{
				perror(NULL);
				break ;
			}
			if (dup2(fds->write, STDOUT_FILENO) == -1)
			{
				perror(NULL);
				break ;
			}
			close(fds->write);		
		}
		tmp = tmp->next;
	}
	if (tmp && tmp->name == COMMAND)
		is_built(&tmp->data.cmd);
	//remettre l'entrée et la sortie standard.
	if (dup2(fds->std_in, STDIN_FILENO) == -1)
		perror(NULL);
	if (dup2(fds->std_out, STDOUT_FILENO) == -1)
		perror(NULL);
	close(fds->std_in);
	close(fds->std_out);
	//free_all_nodes(&lst);
	return ;
}

static int	type_of_cmd(t_data *lst)
{
	t_data	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->name == COMMAND)
			return (tmp->data.cmd.id);
		tmp = tmp->next;
	}
	return (-2);
}

void	normal_execution(t_data *cmdline)
{
	int		type;
	t_fd	fds;
	
	//here_doc(cmdline, &fds.hdoc);
	type = type_of_cmd(cmdline);
	if (type >= 0)
		builtin_execution(cmdline, &fds);
	//else if (type == -1)
	//	command_execution(cmdline, &fds);
//	else
//		redirection quelque chose;
	return ;
}
