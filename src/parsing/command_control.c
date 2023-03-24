/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:02:47 by jduval            #+#    #+#             */
/*   Updated: 2023/03/24 17:29:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*type_of_command(t_data *data, char **path)
{
	
}

t_data	*command_manager(t_data **head)
{
	t_data	*tmp;
	char	*command;

	tmp = (*head);
	while (tmp != NULL)
	{
		if (tmp->name == COMMAND)
		{
			command = tmp->data.cmd.cmd[0];
			command = type_of_command(tmp->data, tmp->data.cmd.utils.path);
			if (command == NULL)
			{
				free_all_nodes((*head));
				return (NULL);
			}
		}
		tmp = tmp->next;
	}
	return ((*head));
}
