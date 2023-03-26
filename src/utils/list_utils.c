/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:37:20 by jduval            #+#    #+#             */
/*   Updated: 2023/03/26 16:25:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/utils.h"

t_data	*new_node_command(char **array, t_mini *utils, int index)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	node->name = COMMAND;
	node->index = index;
	node->next = NULL;
	node->data.cmd.cmd = array;
	node->data.cmd.mini = utils;
	node->data.cmd.id = 0;
	node->data.cmd.valid = -1;
	return (node);
}

t_data	*new_node_redirect(t_class name, char *file, t_way way, int index)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	node->name = name;
	node->index = index;
	node->data.rdict.file = file;
	node->data.rdict.way = way;
	node->data.rdict.fd = 0;
	node->next = NULL;
	return (node);
}

void	add_back_node(t_data **head, t_data *node)
{
	t_data	*tmp;

	if (head == NULL || node == NULL)
		return ;
	if ((*head) == NULL)
		*head = node;
	else
	{
		tmp = reach_last_node(*head);
		tmp->next = node;
	}
	return ;
}

t_data	*reach_last_node(t_data *head)
{
	t_data	*tmp;

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
