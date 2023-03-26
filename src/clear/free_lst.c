/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:57:41 by jduval            #+#    #+#             */
/*   Updated: 2023/03/24 14:48:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"
#include "../../includes/enum.h"

void	free_all_nodes(t_data **head)
{
	t_data	*tmp;
	int		i;

	while (*head != NULL)
	{
		tmp = *head;
		if (tmp->name == REDIRECT)
			free((*head)->data.rdict.file);
		else
		{
			i = 0;
			while (tmp->data.cmd.cmd[i])
			{
				free(tmp->data.cmd.cmd[i]);
				i++;
			}
			free(tmp->data.cmd.cmd);
		}
		*head = (*head)->next;
		free(tmp);
	}
}