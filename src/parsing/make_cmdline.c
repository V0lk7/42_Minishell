/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmdline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:42:19 by jduval            #+#    #+#             */
/*   Updated: 2023/03/22 13:34:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/parsing.h"

/*
t_type	*make_ulst_minishell(char *str, t_mini *utils)
{
	t_type	*head;
	t_type	*tmp;
	char	**array;

	head = NULL;
	array = pipe_separation(str);
	if (array == NULL)
		return (NULL);
	while (array[i])
	{
		if (head == NULL)
			head = nodes_creator(array, i, utils);
		tmp = nodes_creator(array, i, utils);
		if (tmp == NULL)
		{
			free_ulst(&head);
			return (NULL);
		}
		add_back(&head, tmp);
		i++;	
	}
	return (head);
}*/
