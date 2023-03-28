/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:46:59 by jduval            #+#    #+#             */
/*   Updated: 2023/03/28 17:55:07 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_bool	is_pipeline(t_data *cmdline)
{
	t_data	*tmp;

	tmp = cmdline;
	while (tmp)
	{
		if (tmp->index > 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int	find_last_sequence(t_data *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst->index);
}

t_data	*next_sequence(t_data *lst)
{
	int	index;

	index = lst->index;
	while (lst)
	{
		if (lst->index > index)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
