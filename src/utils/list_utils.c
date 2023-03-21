/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:37:20 by jduval            #+#    #+#             */
/*   Updated: 2023/03/21 17:40:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"

t_data	*new_node_redirect(t_class name, char *file, t_way way)
{
	t_data	*node;
	t_type	*type;

	node = malloc(sizeof(t_data));
	if (node == NULL)
		return (NULL);
	type = malloc(sizeof(t_type));
	if (type == NULL)
	{
		free(node);
		return (NULL);
	}
	node->data = type;
	node->name = name;
	node->data->rdict.file = file;
	node->data->rdict.way = way;
	node->data->rdict.fd = 0;
	node->next = NULL;
	return (node);
}
/*
void	add_back_node(t_type **head, t_type *node)
{
	t_type	*tmp;

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

t_type	*reach_last_node(t_type *head)
{
	t_type	*tmp;

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
}*/
