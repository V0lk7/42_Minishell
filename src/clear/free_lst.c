/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:57:41 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 16:10:01 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/clear.h"
#include "../../includes/enum.h"
#include "../libft/include/libft.h"
#include <stdlib.h>

void	free_hdoc(t_hdoc *input)
{
	t_hdoc	*tmp;

	while (input != NULL)
	{
		tmp = input;
		free(tmp->line);
		input = input->next;
		free(tmp);
	}
}

void	free_all_nodes(t_data **head)
{
	t_data	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		if (tmp->name == REDIRECT)
		{
			free_array2d(tmp->data.rdict.file);
			free(tmp->data.rdict.save);
			if (tmp->data.rdict.way == HDOC)
			{
				if (tmp->data.rdict.r_fd > 0)
					close (tmp->data.rdict.r_fd);
				free_hdoc(tmp->data.rdict.input);
			}
		}
		else
			free_array2d(tmp->data.cmd.cmd);
		*head = (*head)->next;
		free(tmp);
	}
}

void	free_lst_expand(t_expand *head)
{
	t_expand	*tmp;

	while (head != NULL)
	{
		tmp = head;
		if (tmp->word != NULL)
			free(tmp->word);
		head = head->next;
		free (tmp);
	}
}
