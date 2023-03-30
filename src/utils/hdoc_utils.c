/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:07:35 by jduval            #+#    #+#             */
/*   Updated: 2023/03/30 18:28:32 by jduval           ###   ########.fr       */
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
	int		len;
	char	name[_POSIX_ARG_MAX];

	i = 0;
	len = 0;
	while (node->fd < 0 && i < 999)
	{
		nbr = ft_itoa(i);
		if (nbr == NULL)
			return (-1);
		len = ft_strlen(nbr);
		ft_strlcpy(name, "/tmp/", 6);
		ft_strlcat(name, nbr, len + 6);
		node->fd = open(name, O_CREAT | O_EXCL | O_WRONLY | O_RDONLY, 0644);
		free (nbr);
		if (node->fd == -1 && errno != EEXIST)
			return (-1);
		i++;
	}
	unlink(name);
	return (node->fd);
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
