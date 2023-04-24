/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_words_splitting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:02:22 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 09:14:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	expansion_wdsplit(char **cmd, t_mini *mini, int *i)
{
	t_expand	*words;

	words = divide_words(cmd->[(*i)]);
	if (words == NULL)
		return (1);
	if(make_expansion(words, mini) == 1)
	{
		free_lst_expand(words);
		return (1);
	}
	if (rebuild_cmd(cmd, i, words) == 1)
	{
		free_lst_expand(words);
		return (1);
	}
	free_lst_expand(words);
	return (0);
}
