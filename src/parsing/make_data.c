/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:04:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/22 18:05:15 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"
/*
t_data	*put_command(const char *str, t_mini *utils, int redirection)
{
	char	**array;
	t_data	*cmd;
	int	i;

	i = 0;
	array = create_array_cmd(str);
	if (array == NULL)
		return (NULL);
	while (i < words[0])
	{
		len = normal_word_lengh(str, array[i + 1]);
		array[i] = ft_substr(str, array[i + 1], len + 1);
		if (array[i] == NULL)
		{
			free_array2d(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	cmd = create_node_command(array, utils);
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}
*/
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

t_data	*put_redirection(const char *str, int nbr)
{
	int		i;
	t_data	*head;
	t_data	*tmp;

	head = NULL;
	i = 0;
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
}
