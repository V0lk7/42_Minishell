/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmdline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:42:19 by jduval            #+#    #+#             */
/*   Updated: 2023/03/23 18:13:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enum.h"
#include "../../includes/parsing.h"
#include "../../includes/utils.h"
#include "../../includes/clear.h"

static t_data	*nodes_creator(char *str, t_mini *utils, int *data)
{
	t_data	*redirect;
	t_data	*cmd;

	if (data[1] > 0)
	{
		redirect = put_redirection(str, data[1] - 1, data[0]);
		if (redirect == NULL)
			return (NULL);
	}
	if (data[2] > 0)
	{
		cmd = create_node_command(str, utils, data[2], data[0]);
		if (cmd == NULL)
		{
			free_all_nodes(&redirect);
			return (NULL);
		}
	}
	if (data[1] > 0 && data[2] > 0)
		add_back_node(&redirect, cmd);
	else if (data[1] <= 0)
		return (cmd);
	return (redirect);
}

static t_data	*node_manager(char *str, int index, t_mini *utils)
{
	t_data	*lst;
	int		data[3];

	data[0] = index;
	data[1] = find_rafter(str);
	data[2] = count_words(str, data[1]);
	lst = nodes_creator(str, utils, data);
	if (lst == NULL)
		return (NULL);
	return (lst);
}

t_data	*make_lst_line(char *str, t_mini *utils)
{
	t_data	*head;
	t_data	*tmp;
	char	**array;
	int		i;

	i = 0;
	array = isolate_by_pipe(str);
	if (array == NULL)
		return (NULL);
	head = node_manager(array[i], i, utils);
	if (head == NULL)
		i = -2;
	while (i > -2 && array[++i])
	{
		tmp = node_manager(array[i], i, utils);
		if (tmp == NULL)
		{
			free_all_nodes(&head);
			free_array2d(array);
			return (NULL);
		}
		add_back_node(&head, tmp);
	}
	free_array2d(array);
	return (head);
}
