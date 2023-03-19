/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:37:20 by jduval            #+#    #+#             */
/*   Updated: 2023/03/19 17:34:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"

t_type	*new_node(t_class name, t_red *redirect, t_cmd *command)
{
	t_type	*node;

	node = malloc(sizeof(t_type));
	if (node == NULL)
		return (NULL);
	node->name = name;
	node->rdct = NULL;
	node->cmd = NULL;
	if (name == COMMAND)
		node->cmd = command;
	else
		node->rdct = redirection;
	node->next = NULL;
	return (node);
}

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
}

int	count_cmd(t_type *head)
{
	t_type	*tmp;
	int		count;

	count = 0;
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->name == COMMAND)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
