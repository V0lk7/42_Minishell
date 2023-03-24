/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:04:02 by jduval            #+#    #+#             */
/*   Updated: 2023/03/23 18:12:46 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../includes/clear.h"
#include "../../includes/enum.h"

t_data	*create_node_command(const char *str, t_mini *utils, int words, int i)
{
	t_data	*cmd;
	char	**array;

	array = fill_array_cmd(str, words);
	if (array == NULL)
		return (NULL);
	cmd = new_node_command(array, utils, i);
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}

t_data	*create_node_redirect(const char *str, int *i, int tmp, int index)
{
	t_data	*node;
	int		len;
	char	*file;

	*i = rafter_index(str, *i);
	len = normal_word_lengh(str, *i);
	file = ft_substr(str, *i, len + 1);
	if (file == NULL)
		return (NULL);
	node = new_node_redirect(REDIRECT, file, rafter_id(str, tmp), index);
	if (node == NULL)
		return (NULL);
	return (node);
}

t_data	*put_redirection(const char *str, int nbr, int index)
{
	int		i;
	t_data	*head;
	t_data	*tmp;

	i = 0;
	head = create_node_redirect(str, &i, i, index);
	if (head == NULL)
		return (NULL);
	while (nbr > 0)
	{
		tmp = create_node_redirect(str, &i, i, index);
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
