/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:04:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/21 17:42:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../includes/enum.h"

t_data	*create_node_redirect(const char *str, int *i, int tmp)
{
	t_data	*node;
	int		len;
	char	*file;

	*i = rafter_index(str, *i);
	len = normal_word_lengh(str, *i);
	file = ft_substr(str, *i, len + 1);
	if (file == NULL)
		return (NULL);
	node = new_node_redirect(REDIRECT, file, rafter_id(str, tmp));
	if (node == NULL)
		return (NULL);
	return (node);
}
/*
t_type	*put_redirection(const char *str, int nbr)
{
	int		i;
	t_type	*head;
	t_type	*tmp;

	head = NULL;
	while (nbr > 0)
	{
		if (head == NULL)
		{
			head = create_node_redirect(str, &i, i);
			if (head == NULL)
				return (NULL);
		}
		tmp = create_node_redirect(str, &i, i);
		if (tmp == NULL)
		{
			free_all_nodes(&head);
			return (NULL);
		}
		add_back_node(&head, tmp);
		nbr--;
	}
	return (head);
}*/
