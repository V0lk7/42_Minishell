/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:17:14 by jduval            #+#    #+#             */
/*   Updated: 2023/03/28 17:44:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/process.h"
#include "../../includes/enum.h"
#include <fcntl.h>
#include <unistd.h>

int	pipe_redirection(t_data *tmp, t_fd *fds, int last)
{
	if (tmp->index == 1)
	{
		if (dup2(fds->write, STDOUT_FILENO) == -1)
			return (1);
		return (0);
	}
	else if (tmp->index == last)
	{
		if (dup2(fds->read, STDIN_FILENO) == -1)
			return (1);
		return (0);
	}
	if (dup2(fds->read, STDIN_FILENO) == -1)
		return (1);
	if (dup2(fds->write, STDOUT_FILENO) == -1)
		return (1);
	return (0);
}

int	pipe_rdir_management(t_data *tmp, t_fd *fds)
{
	int	last;
	int	flag;

	last = find_last_sequence(tmp);
	flag = pipe_redirection(tmp, fds, last);
	if (tmp->index > 1 && tmp->index <= last)
		close(fds->read);
	close(fds->write);
	close(fds->fds[0]);
	return (flag);
}

t_data	*redirection_management(t_data *lst, t_fd *fds, int	index)
{
	t_way	type;

	while (lst && lst->name == REDIRECTION && lst->index == index)
	{
		type = lst->data.rdict.way;
		if (type == IN || type == HDOC)
		{
			if (in_redirection(&lst->data.rdict, fds) == -1)
				break ;
		}
		else if (type == OUT || type == APPEND)
		{
			if (out_redirection(&lst->data.rdict, fds) == -1)
				break ;
		}
		lst = lst->next;
	}
	return (lst);
}

int	in_redirection(t_red *rdict, t_fd *fds)
{
	if (rdict->way == IN)
		fds->read = open(rdict->file, O_RDONLY);
	else
		fds->read = rdict->fd;
	if (fds->read == -1)
	{
		perror(NULL);
		return (-1);
	}
	if (dup2(fds->read, STDIN_FILENO) == -1)
	{
		perror(NULL);
		return (-1);
	}
	close(fds->read);
	return (0);
}

int	out_redirection(t_red *rdict, t_fd *fds)
{
	if (rdict->way == OUT)
		fds->write = open(rdict->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else
		fds->write = open(rdict->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fds->write == -1)
	{
		perror(NULL);
		return (-1);
	}
	if (dup2(fds->write, STDOUT_FILENO) == -1)
	{
		perror(NULL);
		return (-1);
	}
	close(fds->write);
	return (0);
}