/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:57:41 by jduval            #+#    #+#             */
/*   Updated: 2023/03/22 14:02:56 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"
#include "../../includes/enum.h"

void	free_all_nodes(t_data **head)
{
	t_data	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		free((*head)->data.rdict.file);
		*head = (*head)->next;
		free(tmp);
	}
}
