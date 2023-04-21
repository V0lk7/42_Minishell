/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:48:18 by jduval            #+#    #+#             */
/*   Updated: 2023/04/21 17:48:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/utils.h"

t_expand	*new_node_expand(char **array, int id)
{
	t_expand	*node;

	node = malloc(sizeof(t_expand));
	if (node == NULL)
		return (NULL);
	node->id = id;
	node->array = array;
	node->next = NULL;
	return (node);
}

void	add_back_expand(t_expand **head, t_expand *node)
{
	t_expand	*tmp;

	if (head == NULL || node == NULL)
		return ;
	if ((*head) == NULL)
		*head = node;
	else
	{
		tmp = reach_last_expand(*head);
		tmp->next = node;
	}
	return ;
}

t_expand	*reach_last_expand(t_data *head)
{
	t_expand	*tmp;

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
