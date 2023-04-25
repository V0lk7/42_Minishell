/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_hdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:06:46 by jduval            #+#    #+#             */
/*   Updated: 2023/04/25 17:49:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	expand_heredoc(t_red *hdoc, t_mini *mini)
{
	t_hdoc	*tmp;

	if (hdoc->expand == 1)
		return (0);
	tmp = hdoc->input;
	while (tmp != NULL)
	{
		if (search_c(tmp->line, '$') > -1)
		{
			tmp->line = expansion(mini, tmp->line, HDOC);
			if (tmp->line == NULL)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
