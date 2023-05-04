/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:07:35 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 14:06:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../libft/include/libft.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>

int	create_tmp_hdoc(t_red *node)
{
	char	*nbr;
	int		i;
	char	name[_POSIX_ARG_MAX];

	i = 0;
	while (node->w_fd < 0 && i < 999)
	{
		nbr = ft_itoa(i);
		if (nbr == NULL)
			return (-1);
		ft_strlcpy(name, "/tmp/", 6);
		ft_strlcat(name, nbr, ft_strlen(nbr) + 6);
		node->w_fd = open(name, O_CREAT | O_EXCL | O_WRONLY, 0644);
		free (nbr);
		if (node->w_fd == -1 && errno != EEXIST)
			return (-1);
		i++;
	}
	node->r_fd = open(name, O_RDONLY);
	unlink(name);
	return (0);
}

t_hdoc	*create_hdoc_node(char *str, int flag)
{
	t_hdoc	*node;

	node = malloc(sizeof(t_hdoc));
	if (node == NULL)
	{
		perror(NULL);
		return (NULL);
	}
	node->line = str;
	node->last = flag;
	node->next = NULL;
	return (node);
}

t_hdoc	*reach_last_hdoc(t_hdoc *head)
{
	t_hdoc	*tmp;

	if (head == NULL)
		return (NULL);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	add_back_hdoc(t_hdoc **head, t_hdoc *node)
{
	t_hdoc	*tmp;

	if (node == NULL)
		return ;
	if ((*head) == NULL)
		*head = node;
	else
	{
		tmp = reach_last_hdoc(*head);
		tmp->next = node;
	}
	return ;
}

void	close_here_doc(t_data *lst)
{
	while (lst)
	{
		if (lst->name == REDIRECTION)
		{
			if (lst->data.rdict.way == HDOC)
				close (lst->data.rdict.r_fd);
		}
		lst = lst->next;
	}
}
