/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:48:18 by jduval            #+#    #+#             */
/*   Updated: 2023/04/20 19:42:19 by jduval           ###   ########.fr       */
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

