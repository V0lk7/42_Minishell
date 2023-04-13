/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:37:20 by jduval            #+#    #+#             */
/*   Updated: 2023/04/13 13:31:11 by jduval           ###   ########.fr       */
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

t_data	*new_node_redirect(t_class name, char **file, t_way way, int index)
{
	t_data	*node;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	node->name = name;
	node->index = index;
	node->data.rdict.file = file;
	node->data.rdict.way = way;
	node->data.rdict.expand = 0;
	node->data.rdict.w_fd = -1;
	node->data.rdict.r_fd = -1;
	node->data.rdict.input = NULL;
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

int	type_of_cmd(t_data *lst)
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
